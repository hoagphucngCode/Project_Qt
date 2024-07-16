#ifndef CLIMATE_H
#define CLIMATE_H

#include <QObject>
#include <QTimer>

// Climodel
class Climodel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int  tempFront READ tempFront WRITE setTempFront NOTIFY tempFrontChanged)
    Q_PROPERTY(int  tempRear READ tempRear WRITE setTempRear NOTIFY tempRearChanged)
    Q_PROPERTY(int  levelFan READ levelFan WRITE setLevelFan NOTIFY levelFanChanged FINAL)
    Q_PROPERTY(bool frontWinDefroster READ frontWinDefroster WRITE setFrontWinDefroster NOTIFY frontWinDefrosterChanged FINAL)
    Q_PROPERTY(bool rearWindDefroster READ rearWindDefroster WRITE setRearWindDefroster NOTIFY rearWindDefrosterChanged FINAL)
    Q_PROPERTY(int  levelHeatSeatFront READ levelHeatSeatFront WRITE setLevelHeatSeatFront NOTIFY levelHeatSeatFrontChanged FINAL)
    Q_PROPERTY(int  levelHeatSeatRear READ levelHeatSeatRear WRITE setLevelHeatSeatRear NOTIFY levelHeatSeatRearChanged FINAL)
    Q_PROPERTY(int  chairAngle READ chairAngle WRITE setChairAngle NOTIFY chairAngleChanged FINAL)

public:
    explicit Climodel(QObject *parent = nullptr);

    // setter - getter
    int tempRear() const;
    void setTempRear(int newTempRear);

    int tempFront() const;
    void setTempFront(int newTempFont);

    int levelFan() const;
    void setLevelFan(int newLevelFan);

    bool frontWinDefroster() const;
    void setFrontWinDefroster(bool newFrontWinDefroster);

    bool rearWindDefroster() const;
    void setRearWindDefroster(bool newRearWindDefroster);

    void checkFrontWindownDefroster();
    void checkRearWindownDefroster();

    int levelHeatSeatFront() const;
    void setLevelHeatSeatFront(int newLevelHeatSeatFront);

    int levelHeatSeatRear() const;
    void setLevelHeatSeatRear(int newLevelHeatSeatRear);

    int chairAngle() const;
    void setChairAngle(int newChairAngle);

signals:
    void tempRearChanged();
    void tempFrontChanged();
    void levelFanChanged();
    void frontWinDefrosterChanged();
    void rearWindDefrosterChanged();
    void levelHeatSeatFrontChanged();
    void levelHeatSeatRearChanged();
    void chairAngleChanged();

private:
    int m_tempRear;
    int m_tempFront;
    int m_levelFan;
    bool m_frontWinDefroster;
    bool m_rearWindDefroster;
    int m_levelHeatSeatFront;
    int m_levelHeatSeatRear;
    int m_chairAngle;
};

#endif // CLIMATE_H
