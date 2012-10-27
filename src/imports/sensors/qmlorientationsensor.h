/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSensors module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QMLORIENTATIONSENSOR_H
#define QMLORIENTATIONSENSOR_H

#include "qmlsensor.h"
#include <QOrientationSensor>

QT_BEGIN_HEADER
QT_BEGIN_NAMESPACE

class QOrientationSensor;

class QmlOrientationSensor : public QmlSensor
{
    Q_OBJECT
public:
    explicit QmlOrientationSensor(QObject *parent = 0);
    ~QmlOrientationSensor();


private:
    QSensor *sensor() const Q_DECL_OVERRIDE;
    QOrientationSensor *m_sensor;
    QmlSensorReading *createReading() const Q_DECL_OVERRIDE;
};

class QmlOrientationSensorReading : public QmlSensorReading
{
    Q_OBJECT
    Q_PROPERTY(QOrientationReading::Orientation orientation READ orientation NOTIFY orientationChanged)
public:

    explicit QmlOrientationSensorReading(QOrientationSensor *sensor);
    ~QmlOrientationSensorReading();

    QOrientationReading::Orientation orientation() const;

Q_SIGNALS:
    void orientationChanged();

private:
    QSensorReading *reading() const Q_DECL_OVERRIDE;
    void readingUpdate() Q_DECL_OVERRIDE;
    QOrientationSensor *m_sensor;
    QOrientationReading::Orientation m_orientation;
};

QT_END_NAMESPACE
QT_END_HEADER
#endif