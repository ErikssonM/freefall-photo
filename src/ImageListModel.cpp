#include "ImageListModel.h"

int ImageListModel::rowCount(const QModelIndex &parent) const
{
  return images.size();
}

QVariant ImageListModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();
  if (index.row() >= images.size())
    return QVariant();
  if (role == Qt::DisplayRole)
    return QVariant::fromValue(images.at(index.row()));
  else
    return QVariant(); 
}

Qt::ItemFlags ImageListModel::flags(const QModelIndex &index) const
{
  return Qt::ItemIsEditable;
}

bool ImageListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
  if (role == Qt::EditRole && index.data().canConvert<ImageItem>())
  {
    ImageItem image = value.value<ImageItem>();
    images[index.row()] = image;
    return true;
  }
  else
    return false;
}

bool ImageListModel::insertRows(int row, int count, const QModelIndex &parent)
{
  beginInsertRows(parent, row, row + count);
  for (int i = row; i < (row + count); i++)
  {
    qDebug("Appending row");
    images.insert(images.begin() + i, ImageItem());
  }
  endInsertRows();
  return true;
}

bool ImageListModel::removeRows(int row, int count, const QModelIndex &parent)
{
  beginRemoveRows(parent, row, row + count);
  images.erase(images.begin() + row, images.begin() + (row + count));
  endRemoveRows();
  return true;
}

bool ImageListModel::appendRow(const QVariant &value)
{
  if (value.canConvert<ImageItem>())
  {
    int currentCount = images.size();
    ImageItem image = value.value<ImageItem>();
    bool insert = insertRows(currentCount, 1);
    qDebug("currentCount %i", currentCount);
    if (insert)
      images[currentCount] = image;
      //images[currentCount + 1] = image;
    //TODO: Use setData instead
    return insert;
  }
  else
    return false;
}