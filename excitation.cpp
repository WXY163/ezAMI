/*
 *     <ezAMI: IBIS-AMI model generation tool>
 *    Copyright (C) 2020
 *   Author: Xinying Wang (xinying@illinois.edu)
 *           Department of Electrical Computer Engineering
 *           University of Illinois at Urbana-Champaign
 *

 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.

 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "excitation.h"

excitation::excitation()
{

}

QVector<qreal> *excitation::getSample()
{
    long numberSample = static_cast<long>(length / timeInterval);
    QVector<qreal> *sample = new QVector<qreal>(numberSample);
    return sample;
}

QVector<qreal> *excitation::getTimeSteps()
{
    long numberSample = static_cast<long>(length / timeInterval);
    QVector<qreal> *timeSteps = new QVector<qreal>(numberSample);
    int i = 0;
    for(auto it = timeSteps->begin(); it != timeSteps->end(); ++it)
    {
        *it = (length/ timeInterval) * i;
        i++;
    }
    return timeSteps;
}
