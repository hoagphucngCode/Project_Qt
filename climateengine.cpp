// climateengine.cpp
#include "climateengine.h"
#include <QDebug>
#include <iostream>

ClimateEngine::ClimateEngine(Climodel *climodel, QObject *parent)
    : QObject(parent),m_model(climodel)
{
}

void ClimateEngine::upTempFront()
{
    m_model->setTempFront(m_model->tempFront()+1);
    qDebug() << "Cpp - Template Front: " << m_model->tempFront();
    std::cout << "Cpp - Template Front: " << m_model->tempFront();
}

void ClimateEngine::downTempFront()
{
    m_model->setTempFront(m_model->tempFront()-1);
    qDebug() << "Cpp - Template Front: " << m_model->tempFront();
}

void ClimateEngine::upTempRear()
{
    m_model->setTempRear(m_model->tempRear()+1);
    qDebug() << "Cpp - Template Rear: " << m_model->tempRear();
}

void ClimateEngine::downTempRear()
{
    m_model->setTempRear(m_model->tempRear()-1);
    qDebug() << "Cpp - Template Rear: " << m_model->tempRear();
}

void ClimateEngine::adjustFanLevel(int level)
{
    if(level >= 0 && level < 6)
    {
        m_model->setLevelFan(level);
        qDebug() << "Cpp - Level Fan: " << m_model->levelFan();
    }
}

void ClimateEngine::adjustHeatSeatLevelFront(int level)
{
    if(level >= 0 && level <= 3)
        m_model->setLevelHeatSeatFront(level);
    qDebug() << "Cpp - Level HeatSeats Front: " << m_model->levelHeatSeatFront();
}

void ClimateEngine::adjustHeatSeatLevelRear(int level)
{
    if(level >= 0 && level <= 3)
        m_model->setLevelHeatSeatRear(level);
    qDebug() << "Cpp - Level HeatSeats Rear: " << m_model->levelHeatSeatRear();
}

void ClimateEngine::adjustAngleChairToUpper()
{
    if(m_model->chairAngle() >= 85 && m_model->chairAngle()  < 160)
    {
        m_model->setChairAngle(m_model->chairAngle()+1);
    }
    qDebug() << "Cpp - Angle Chair: " << m_model->chairAngle();
}

void ClimateEngine::adjustAngleChairToLower()
{
    if(m_model->chairAngle() >= 85 && m_model->chairAngle()  < 160)
    {
        m_model->setChairAngle(m_model->chairAngle()-1);
    }
    qDebug() << "Cpp - Angle Chair: " << m_model->chairAngle();
}

void ClimateEngine::controlFrontWindowDefroster(bool check)
{
    m_model->setFrontWinDefroster(check);
    if(m_model->frontWinDefroster())
        qDebug() << "Cpp - Turn on Front Window Defroster";
    else if(m_model->frontWinDefroster() == false)
        qDebug() << "Cpp - Turn off Front Window Defroster";
}

void ClimateEngine::controlRearWindowDefroster(bool check)
{
    m_model->setRearWindDefroster(check);
    if(m_model->rearWindDefroster())
        qDebug() << "Cpp - Turn on Rear Window Defroster";
    else if(m_model->rearWindDefroster() == false)
        qDebug() << "Cpp - Turn off Rear Window Defroster";
}








