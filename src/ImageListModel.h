#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <QAbstractListModel>
#include "ImageItem.h"

class ImageListModel : public QAbstractListModel
{
  Q_OBJECT

public:
  ImageListModel(QObject *parent = nullptr)
    : QAbstractListModel(parent) {};

  //Overrides
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index, int role) const override;
  //QVariant headerData(int section)
  Qt::ItemFlags flags(const QModelIndex &index) const override;
  bool setData(const QModelIndex &index, const QVariant &value,
               int role = Qt::EditRole) override;
  bool insertRows(int row, int count,
                  const QModelIndex &parent = QModelIndex()) override;
  bool removeRows(int row, int count,
                  const QModelIndex &parent = QModelIndex()) override;

  //Other functions?
  bool appendRow(const QVariant &value);

private:
  std::vector<ImageItem> images;
  //std::vector<OpenImage> images;
  //std::vector<QString> images;
};

#endif