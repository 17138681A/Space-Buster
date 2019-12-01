#include "Guide.h"

Guide::Guide(double x, double y, QObject* parent){


    pix = QPixmap(":/image/guide.png");
    setPixmap(pix);
    setScale(0.8);
    setPos(x-pixmap().width()*scale()/2, y-pixmap().height()*scale()/2);

}