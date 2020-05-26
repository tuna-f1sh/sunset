/*
 * Provides the ability to calculate the local time for sunrise,
 * sunwet, and moonrise at any point in time at any location in the world
 *
 * Original work used with permission maintaining license
 * Copyright (GPL) 2004 Mike Chirico mchirico@comcast.net
 * Modifications copyright
 * Copyright (GPL) 2015 Peter Buelow
 *
 * This file is part of the Sunset library
 *
 * Sunset is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * Sunset is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.    If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SUNPOSITION_H__
#define __SUNPOSITION_H__

#include <cmath>
#include <ctime>

#define SUNSET_OFFICIAL         90.833
#define SUNSET_NAUTICAL         102
#define SUNSET_CIVIL            96
#define SUNSET_ASTONOMICAL      108

#define SUNSET_INVALID_TZ_D     99.9
#define SUNSET_INVALID_TZ_I     99

class SunSet {
public:
    SunSet();
    SunSet(double, double, int);
    SunSet(double, double, double);
    ~SunSet();

    void setPosition(double, double, int);
    void setPosition(double, double, double);
    void setTZOffset(int);
    void setTZOffset(double);
    double setCurrentDate(int, int, int);
    double calcNauticalSunriseUTC();
    double calcNauticalSunsetUTC();
    double calcNauticalSunriseLocal();
    double calcNauticalSunsetLocal();
    double calcCivilSunriseLocal();
    double calcCivilSunsetLocal();
    double calcAstronomicalSunriseLocal();
    double calcAstronomicalSunsetLocal();
    double calcSunriseUTC();
    double calcSunsetUTC();
    double calcSunriseLocal();
    double calcSunsetLocal();
    double calcSunrise();
    double calcSunset();
    int moonPhase(int);
    int moonPhase();

private:
    double degToRad(double);
    double radToDeg(double);
    double calcMeanObliquityOfEcliptic(double);
    double calcGeomMeanLongSun(double);
    double calcObliquityCorrection(double);
    double calcEccentricityEarthOrbit(double);
    double calcGeomMeanAnomalySun(double);
    double calcEquationOfTime(double);
    double calcTimeJulianCent(double);
    double calcSunTrueLong(double);
    double calcSunApparentLong(double);
    double calcSunDeclination(double);
    double calcHourAngleSunrise(double, double, double);
    double calcHourAngleSunset(double, double, double);
    double calcJD(int,int,int);
    double calcJDFromJulianCent(double);
    double calcSunEqOfCenter(double);
    double calcAbsSunrise(double);
    double calcAbsSunset(double);

    double m_latitude;
    double m_longitude;
    double m_julianDate;
    int m_year;
    int m_month;
    int m_day;
    double m_tzOffset;
};

#endif
