//Day 4
#include "Equiment.h"
#include "Jet.h"

Equipment::Equipment(EquipmentName equipment, double x, double y, QTimer* timer, QObject* parent)
{

//    randNum = rand()%4;
    name = equipment;
    refreshRate = timer;
    randDirOfX = -1 + 2*(rand()%2);
    randDirOfY = -1 + 2*(rand()%2);

//    if(randNum == 0){
//        randDirOfX = 1;
//        randDirOfY = 1;

//    }else if(randNum == 1){
//        randDirOfX = 1;
//        randDirOfY = -1;

//    }else if(randNum == 2){
//        randDirOfX = -1;
//        randDirOfY = 1;

//    }else if(randNum == 3){
//        randDirOfX = -1;
//        randDirOfY = -1;
//    }


    if(name == STORMER_PACK)
        pix = QPixmap(":/image/flakker.png");

    else if(name == ULTRA_STORMER_PACK)
        pix = QPixmap(":/image/ultra_flakker.png");

    else if(name == HEALTH_PACK)
        pix = QPixmap(":/image/healthpack.png");

    else if(name == FRENZY_PACK)
        pix = QPixmap(":/image/frenzy.png");


    setPixmap(pix);
    setStep(1);
    setPos(x,y);
    setScale(0.1);


    connect(refreshRate, SIGNAL(timeout()), this, SLOT(move()));

}

void Equipment::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        Jet* jet = dynamic_cast<Jet*>(colliding_items[i]);

              if(jet != nullptr){

                emit equipped(name);
                delete this;
                return;

            }
        }//Day 5


    if(y() <= 0)
        randDirOfY = 1;

    if(x() <= 0)
        randDirOfX = 1;

    if(y() >= 960 - pixmap().height()*scale())
        randDirOfY = -1;

    if(x() >= 1280 - pixmap().width()*scale())
        randDirOfX = -1;

    setPos(x()+step*randDirOfX, y()+step*randDirOfY);


}
