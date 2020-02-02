/*
***************************************************************************
*
* Author: Teunis van Beelen
*
* Copyright (C) 2014 - 2020 Teunis van Beelen
*
* Email: teuniz@protonmail.com
*
***************************************************************************
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
***************************************************************************
*/


#ifndef UI_MIT2EDFFORM_H
#define UI_MIT2EDFFORM_H


#include <QtGlobal>
#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QObject>
#include <QTextEdit>
#include <QFileDialog>
#include <QCursor>
#include <QStyle>
#if QT_VERSION < 0x050000
#include <QPlastiqueStyle>
#include <QWindowsStyle>
#endif
#include <QProgressDialog>
#include <QString>
#include <QByteArray>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "utils.h"
#include "edflib.h"
#include "utc_date_time.h"



class UI_MIT2EDFwindow : public QObject
{
  Q_OBJECT

public:
  UI_MIT2EDFwindow(char *recent_dir=NULL, char *save_dir=NULL);

private:


QPushButton  *pushButton1,
             *pushButton2;

QTextEdit    *textEdit1;

QDialog      *myobjectDialog;

char  *recent_opendir,
      *recent_savedir;

struct {
        int chns;
        int sf_base;
        int sf_frame[MAXSIGNALS];
        int sf_div;
        int sf_block;
        int sf_multiple;
        long long smp_period;
        long long smp_period_frame[MAXSIGNALS];
        int format[MAXSIGNALS];
        double adc_gain[MAXSIGNALS];
        int baseline[MAXSIGNALS];
        int baseline_present[MAXSIGNALS];
        int adc_resolution[MAXSIGNALS];
        int adc_zero[MAXSIGNALS];
        int init_val[MAXSIGNALS];
        char label[MAXSIGNALS][17];
        int unit_multiplier[MAXSIGNALS];
        char unit[MAXSIGNALS][9];
      } mit_hdr;


private slots:

void SelectFileButton();

};




#endif


