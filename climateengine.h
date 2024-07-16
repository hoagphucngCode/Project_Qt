// climateengine.h

#ifndef CLIMATEENGINE_H
#define CLIMATEENGINE_H

#include <QObject>
#include <QDebug>
#include "models/climodel.h"

class ClimateEngine : public QObject
{
    Q_OBJECT
public:
    explicit ClimateEngine(Climodel* climodel, QObject *parent = nullptr);

public slots:
    // Temp Rear
    void upTempFront();
    void downTempFront();
    // Temp Rear
    void upTempRear();
    void downTempRear();
    // LevelFan
    void adjustFanLevel(int level);
    // // Level HeatSeat
    void adjustHeatSeatLevelFront(int level);
    void adjustHeatSeatLevelRear(int level);
    // // Adjust Angel Chair
    void adjustAngleChairToUpper();
    void adjustAngleChairToLower();
    //
    void controlFrontWindowDefroster(bool check);
    void controlRearWindowDefroster(bool check);

private:
    Climodel *m_model = nullptr;
};

#endif // CLIMATEENGINE_H
