#include "climodel.h"
#include <QDebug>

Climodel::Climodel(QObject *parent)
    : QObject{parent},m_tempFront(72),m_tempRear(83),m_levelFan(0),
    m_frontWinDefroster(false),
    m_rearWindDefroster(false),
    m_chairAngle(90),
    m_levelHeatSeatFront(0),
    m_levelHeatSeatRear(0)
{}

int Climodel::tempRear() const
{
    return m_tempRear;
}

void Climodel::setTempRear(int newTempRear)
{
    if (m_tempRear == newTempRear)
        return;
    m_tempRear = newTempRear;
    emit tempRearChanged();
}

int Climodel::tempFront() const
{
    return m_tempFront;
}

void Climodel::setTempFront(int newTempFont)
{
    if (m_tempFront == newTempFont)
        return;
    m_tempFront = newTempFont;
    emit tempFrontChanged();
}

int Climodel::levelFan() const
{
    return m_levelFan;
}

void Climodel::setLevelFan(int newLevelFan)
{
    if (m_levelFan == newLevelFan)
        return;
    m_levelFan = newLevelFan;
    emit levelFanChanged();

}

bool Climodel::frontWinDefroster() const
{
    return m_frontWinDefroster;
}

void Climodel::setFrontWinDefroster(bool newFrontWinDefroster)
{
    if (m_frontWinDefroster == newFrontWinDefroster)
        return;
    m_frontWinDefroster = newFrontWinDefroster;
    emit frontWinDefrosterChanged();
}

bool Climodel::rearWindDefroster() const
{
    return m_rearWindDefroster;
}

void Climodel::setRearWindDefroster(bool newRearWindDefroster)
{
    if (m_rearWindDefroster == newRearWindDefroster)
        return;
    m_rearWindDefroster = newRearWindDefroster;
    emit rearWindDefrosterChanged();
}


int Climodel::levelHeatSeatFront() const
{
    return m_levelHeatSeatFront;
}

void Climodel::setLevelHeatSeatFront(int newLevelHeatSeatFront)
{
    if (m_levelHeatSeatFront == newLevelHeatSeatFront)
        return;
    m_levelHeatSeatFront = newLevelHeatSeatFront;
    emit levelHeatSeatFrontChanged();
}

int Climodel::levelHeatSeatRear() const
{
    return m_levelHeatSeatRear;
}

void Climodel::setLevelHeatSeatRear(int newLevelHeatSeatRear)
{
    if (m_levelHeatSeatRear == newLevelHeatSeatRear)
        return;
    m_levelHeatSeatRear = newLevelHeatSeatRear;
    emit levelHeatSeatRearChanged();
}

int Climodel::chairAngle() const
{
    return m_chairAngle;
}

void Climodel::setChairAngle(int newChairAngle)
{
    if (m_chairAngle == newChairAngle)
        return;
    m_chairAngle = newChairAngle;
    emit chairAngleChanged();
}

