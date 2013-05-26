#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QtGui/QApplication>
#include <QApplication>
#include <QtGui>
#include <QLabel>
#include <QString>
#include <QFileDialog>
#include <QHash>
#include <QHashIterator>

class ImageHandler
{

private:

    //variables
    QImage targetImage,sourceImage;
    QPixmap sourcePixmap;
    QRgb sourceColor, sourcePixel;
    QString sourceImageLocation;
    QStringList sourceImagesLocation;
    QHash<QRgb, QImage> hash;
    QLabel sourceImageLabel, targetImageLabel;
    int targetWidth, targetHeight;
    int sourceWidth, sourceHeight;
    int tileWidth, tileHeight;

    // functions
    void prepareSourceImages();
    void prepareHash ();
    void setParameters();
    QRgb getTileAvarage(QImage image);
    void setSourceColor(int i, int j);
    void makeMosaic();


public:
    ImageHandler();
    void Run();
};



#endif // IMAGEHANDLER_H
