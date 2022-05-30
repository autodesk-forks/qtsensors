/****************************************************************************
**
** Copyright (C) 2022 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSensors module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
******************************************************************************/

#include "sensorfwrotationsensor.h"

char const * const SensorfwRotationSensor::id("sensorfw.rotationsensor");

SensorfwRotationSensor::SensorfwRotationSensor(QSensor *sensor)
    : SensorfwSensorBase(sensor)
    , m_initDone(false)
{
    init();
    setReading<QRotationReading>(&m_reading);
    QRotationSensor *const rotationSensor = qobject_cast<QRotationSensor *>(sensor);
    if (rotationSensor)
        rotationSensor->setHasZ(true);
    sensor->setDataRate(20);//set a default rate
}

void SensorfwRotationSensor::slotDataAvailable(const XYZ& data)
{
    m_reading.setFromEuler(data.x(),data.y(),data.z());
    m_reading.setTimestamp(data.XYZData().timestamp_);
    newReadingAvailable();
}

void SensorfwRotationSensor::slotFrameAvailable(const QList<XYZ> &frame)
{
    for (int i=0, l=frame.size(); i<l; i++) {
        slotDataAvailable(frame.at(i));
    }
}

bool SensorfwRotationSensor::doConnect()
{
    Q_ASSERT(m_sensorInterface);
    if (m_bufferSize==1)
       return QObject::connect(m_sensorInterface, SIGNAL(dataAvailable(XYZ)), this, SLOT(slotDataAvailable(XYZ)));
    return QObject::connect(m_sensorInterface, SIGNAL(frameAvailable(QList<XYZ>)), this,
                            SLOT(slotFrameAvailable(QList<XYZ>)));
}

QString SensorfwRotationSensor::sensorName() const
{
    return "rotationsensor";
}

void SensorfwRotationSensor::init()
{
    m_initDone = false;
    initSensor<RotationSensorChannelInterface>(m_initDone);
}

void SensorfwRotationSensor::start()
{
    if (reinitIsNeeded)
        init();
    SensorfwSensorBase::start();
}
