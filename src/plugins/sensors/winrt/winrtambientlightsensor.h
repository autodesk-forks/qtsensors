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

#ifndef WINRTAMBIENTLIGHTSENSOR_H
#define WINRTAMBIENTLIGHTSENSOR_H

#include <QtSensors/QSensorBackend>
#include <QtCore/QScopedPointer>

QT_USE_NAMESPACE

class WinRtAmbientLightSensorPrivate;
class WinRtAmbientLightSensor : public QSensorBackend
{
    Q_OBJECT
public:
    WinRtAmbientLightSensor(QSensor *sensor);
    ~WinRtAmbientLightSensor();

    void start() override;
    void stop() override;

private:
    QScopedPointer<WinRtAmbientLightSensorPrivate> d_ptr;
    Q_DECLARE_PRIVATE(WinRtAmbientLightSensor)
};

#endif // WINRTAMBIENTLIGHTSENSOR_H
