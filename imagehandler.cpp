#include "imagehandler.h"

ImageHandler::ImageHandler()
{
}

QRgb ImageHandler::getTileAvarage(QImage image)
{
    int sumR, sumG, sumB, avarageR, avarageG, avarageB;
    QRgb tempPixel;
    for (int k = 0; k < tileWidth; k++)
    {
        for (int m = 0; m < tileHeight; m++)
        {
                tempPixel = image.pixel(k, m);
                sumR += qRed(tempPixel);
                sumG += qGreen(tempPixel);
                sumB += qBlue(tempPixel);
        }
    }
    avarageR = sumR/(tileWidth * tileHeight);
    avarageG = sumG/(tileWidth * tileHeight);
    avarageB = sumB/(tileWidth * tileHeight);

    tempPixel = qRgb(avarageR, avarageG, avarageB);

    return tempPixel;
}

void ImageHandler::prepareSourceImages()
{
    // Get source images location

    QStringList list = QFileDialog::getOpenFileNames();


        int length = list.length();

        for(int i=0; i<length; i++)
        {

            QString str = list.at(i);

            QPixmap pixmap(str);
            QImage image = pixmap.toImage();
            qDebug() << str << "\n";
            image = image.scaled(tileWidth, tileHeight);
            targetImage = image;
            QRgb imageAvarage = getTileAvarage(image);
            qDebug() << imageAvarage << "\n";

            hash.insert(imageAvarage, image);

//            QRgb key;
//            foreach( key, hash.keys() )
//                qDebug() << key << " = " << hash[key];

        }
}

void ImageHandler::setParameters()
{
    sourceWidth = sourcePixmap.width();
    sourceHeight = sourcePixmap.height();
    targetWidth = sourceWidth;
    targetHeight = sourceHeight;
    tileWidth = 30;
    tileHeight = 30;
}

void ImageHandler::setSourceColor(int i, int j)
{
    int sumR, sumG, sumB, avarageR, avarageG, avarageB;
    QRgb tempPixel;
    for (int k = 0; k < tileWidth; k++)
    {
        for (int m = 0; m < tileHeight; m++)
        {
            if (i+k < sourceWidth && j+m < sourceHeight)
            {
                tempPixel = sourceImage.pixel(i+k, j+m);
                sumR += qRed(tempPixel);
                sumG += qGreen(tempPixel);
                sumB += qBlue(tempPixel);
            }
        }
    }
    avarageR = sumR/(tileWidth * tileHeight);
    avarageG = sumG/(tileWidth * tileHeight);
    avarageB = sumB/(tileWidth * tileHeight);

    sourceColor = qRgb(avarageR, avarageG, avarageB);
}

void ImageHandler::makeMosaic()
{
    // define temp variables
    int r1, g1, b1;
    // the main process
    for (int i = 0; i < sourceWidth; ++i)
    {
       for (int j = 0; j < sourceHeight; ++j)
       {
           setSourceColor(i, j);
           for (int k = 0; k < tileWidth; k++)
           {
               for (int m = 0; m < tileWidth; m++)
               {
                   if ((i+k < targetWidth) && (j+m < targetHeight))
                   {
                       // making the mosaic
                       r1 = qRed(sourceColor);
                       g1 = qGreen(sourceColor);
                       b1 = qBlue(sourceColor);
                       sourcePixel = qRgb(r1, g1, b1);
                       targetImage.setPixel(i+k, j+m, sourcePixel);
                   }
               }
           }
           // jump verticaly
           j += tileHeight;
       }
       // jump horizentaly
       i += tileWidth;
    }
}

void ImageHandler::Run()
{
//    // Get source image location
//    sourceImageLocation = QFileDialog::getOpenFileName();

//    // Set source image
//    QPixmap pixmap(sourceImageLocation);
//    sourcePixmap = pixmap;
//    sourceImage = pixmap.toImage();


    // set parameters
    setParameters();

//    // Prepare target image
//    targetImage = sourceImage.copy(0, 0, sourceWidth, sourceHeight);

    prepareSourceImages();

//    // Make mosaic
//    makeMosaic();

//    // Show original image
//    sourceImageLabel.setPixmap(QPixmap::fromImage(sourceImage));
//    sourceImageLabel.show();

    // Show target image
    targetImageLabel.setPixmap(QPixmap::fromImage(targetImage));
    targetImageLabel.show();

}
