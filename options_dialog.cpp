/*
***************************************************************************
*
* Author: Teunis van Beelen
*
* Copyright (C) 2007 - 2021 Teunis van Beelen
*
* Email: teuniz@protonmail.com
*
***************************************************************************
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3 of the License.
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



#include "options_dialog.h"




UI_OptionsDialog::UI_OptionsDialog(QWidget *w_parent)
{
  int i;

  mainwindow = (UI_Mainwindow *)w_parent;

  optionsdialog = new QDialog(w_parent);

  optionsdialog->setWindowTitle("Settings");
  optionsdialog->setModal(true);
  optionsdialog->setAttribute(Qt::WA_DeleteOnClose, true);

  tabholder = new QTabWidget;

  CloseButton = new QPushButton;
  CloseButton->setText("Close");

  QHBoxLayout *hlayout_tmp;

  QVBoxLayout *vlayout_tmp;

/////////////////////////////////////// tab 1 Colors ///////////////////////////////////////////////////////////////////////

  tab1 = new QWidget;

  QFormLayout *flayout1_1 = new QFormLayout;
  flayout1_1->setSpacing(20);

  BgColorButton = new SpecialButton;
  BgColorButton->setColor(mainwindow->maincurve->backgroundcolor);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(BgColorButton);
  hlayout_tmp->addStretch(1000);
  flayout1_1->addRow("Background color", hlayout_tmp);

  SrColorButton = new SpecialButton;
  SrColorButton->setColor(mainwindow->maincurve->small_ruler_color);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(SrColorButton);
  hlayout_tmp->addStretch(1000);
  flayout1_1->addRow("Small ruler color", hlayout_tmp);

  BrColorButton = new SpecialButton;
  BrColorButton->setColor(mainwindow->maincurve->big_ruler_color);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(BrColorButton);
  hlayout_tmp->addStretch(1000);
  flayout1_1->addRow("Big ruler color", hlayout_tmp);

  MrColorButton = new SpecialButton;
  MrColorButton->setColor(mainwindow->maincurve->mouse_rect_color);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(MrColorButton);
  hlayout_tmp->addStretch(1000);
  flayout1_1->addRow("Mouse rectangle color", hlayout_tmp);

  TxtColorButton = new SpecialButton;
  TxtColorButton->setColor(mainwindow->maincurve->text_color);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(TxtColorButton);
  hlayout_tmp->addStretch(1000);
  flayout1_1->addRow("Text color", hlayout_tmp);

  SigColorButton = new SpecialButton;
  SigColorButton->setColor((Qt::GlobalColor)mainwindow->maincurve->signal_color);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(SigColorButton);
  hlayout_tmp->addStretch(1000);
  flayout1_1->addRow("Signals color", hlayout_tmp);

  checkbox16 = new QCheckBox;
  checkbox16->setTristate(false);
  checkbox16->setToolTip("When adding signals to the screen, vary the traces' color");
  if(mainwindow->use_diverse_signal_colors)
  {
    checkbox16->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox16->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox16);
  hlayout_tmp->addStretch(1000);
  flayout1_1->addRow("Vary signal colors", hlayout_tmp);

  checkbox3 = new QCheckBox;
  checkbox3->setTristate(false);
  if(mainwindow->show_baselines)
  {
    checkbox3->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox3->setCheckState(Qt::Unchecked);
  }
  BaseColorButton = new SpecialButton;
  BaseColorButton->setColor(mainwindow->maincurve->baseline_color);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox3);
  hlayout_tmp->addWidget(BaseColorButton);
  hlayout_tmp->addStretch(1000);
  flayout1_1->addRow("Baseline color", hlayout_tmp);

  Crh1ColorButton = new SpecialButton;
  Crh1ColorButton->setColor((Qt::GlobalColor)mainwindow->maincurve->crosshair_1.color);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(Crh1ColorButton);
  hlayout_tmp->addStretch(1000);
  flayout1_1->addRow("First Crosshair color", hlayout_tmp);

  QFormLayout *flayout1_2 = new QFormLayout;
  flayout1_2->setSpacing(20);

  Crh2ColorButton = new SpecialButton;
  Crh2ColorButton->setColor((Qt::GlobalColor)mainwindow->maincurve->crosshair_2.color);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(Crh2ColorButton);
  hlayout_tmp->addStretch(1000);
  flayout1_2->addRow("Second Crosshair color", hlayout_tmp);

  FrColorButton = new SpecialButton;
  FrColorButton->setColor((Qt::GlobalColor)mainwindow->maincurve->floating_ruler_color);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(FrColorButton);
  hlayout_tmp->addStretch(1000);
  flayout1_2->addRow("Floating ruler color", hlayout_tmp);

  checkbox2 = new QCheckBox;
  checkbox2->setTristate(false);
  if(mainwindow->show_annot_markers)
  {
    checkbox2->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox2->setCheckState(Qt::Unchecked);
  }
  AnnotMkrButton = new SpecialButton;
  AnnotMkrButton->setColor(mainwindow->maincurve->annot_marker_color);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox2);
  hlayout_tmp->addWidget(AnnotMkrButton);
  hlayout_tmp->addStretch(1000);
  flayout1_2->addRow("Annotation marker", hlayout_tmp);

  checkbox2_1 = new QCheckBox;
  checkbox2_1->setTristate(false);
  if(mainwindow->annotations_show_duration)
  {
    checkbox2_1->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox2_1->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox2_1);
  hlayout_tmp->addStretch(1000);
  flayout1_2->addRow("Show duration at marker", hlayout_tmp);

  AnnotDurationButton = new SpecialButton;
  AnnotDurationButton->setColor(mainwindow->maincurve->annot_duration_color);
  AnnotDurationButton->setToolTip("The second color is used to indicate if it's selected");
  AnnotDurationSelectedButton = new SpecialButton;
  AnnotDurationSelectedButton->setColor(mainwindow->maincurve->annot_duration_color_selected);
  AnnotDurationSelectedButton->setToolTip("The second color is used to indicate if it's selected");
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(AnnotDurationButton);
  hlayout_tmp->addWidget(AnnotDurationSelectedButton);
  hlayout_tmp->addStretch(1000);
  flayout1_2->addRow("Annotation duration background", hlayout_tmp);

  checkbox2_2 = new QCheckBox;
  checkbox2_2->setTristate(false);
  if(mainwindow->annotations_duration_background_type)
  {
    checkbox2_2->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox2_2->setCheckState(Qt::Unchecked);
  }
  checkbox2_2->setToolTip("Show the colored background only at the bottom of the screen");
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox2_2);
  hlayout_tmp->addStretch(1000);
  flayout1_2->addRow("Show only at screen bottom", hlayout_tmp);

  checkbox5 = new QCheckBox;
  checkbox5->setTristate(false);
  checkbox5->setToolTip("Annotation filter affects the annotationlist only, not the annotation markers in the signal window");
  if(mainwindow->annot_filter->hide_in_list_only)
  {
    checkbox5->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox5->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox5);
  hlayout_tmp->addStretch(1000);
  flayout1_2->addRow("Annotations: filter list only", hlayout_tmp);

  checkbox1 = new QCheckBox;
  checkbox1->setTristate(false);
  if(mainwindow->maincurve->blackwhite_printing)
  {
    checkbox1->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox1->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox1);
  hlayout_tmp->addStretch(1000);
  flayout1_2->addRow("Print in grayscale", hlayout_tmp);

  checkbox4 = new QCheckBox;
  checkbox4->setTristate(false);
  if(mainwindow->clip_to_pane)
  {
    checkbox4->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox4->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox4);
  hlayout_tmp->addStretch(1000);
  flayout1_2->addRow("Clip signals to pane", hlayout_tmp);

  colorSchema_Dark_Button = new QPushButton;
  colorSchema_Dark_Button->setText("\"Dark\"");

  colorSchema_NK_Button = new QPushButton;
  colorSchema_NK_Button->setText("\"NK\"");

  colorSchema_Blue_on_Gray_Button = new QPushButton;
  colorSchema_Blue_on_Gray_Button->setText("\"Blue on gray\"");

  saveColorSchemaButton = new QPushButton;
  saveColorSchemaButton->setText("Save");

  loadColorSchemaButton = new QPushButton;
  loadColorSchemaButton->setText("Load");

  QVBoxLayout *vlayout1_4 = new QVBoxLayout;
  vlayout1_4->addStretch(100);
  vlayout1_4->addWidget(colorSchema_Dark_Button);
  vlayout1_4->addWidget(colorSchema_NK_Button);
  vlayout1_4->addWidget(colorSchema_Blue_on_Gray_Button);
  vlayout1_4->addWidget(saveColorSchemaButton);
  vlayout1_4->addWidget(loadColorSchemaButton);
  vlayout1_4->addStretch(100);

  QHBoxLayout *hlayout1_2 = new QHBoxLayout;
  hlayout1_2->addStretch(100);
  hlayout1_2->addLayout(vlayout1_4);
  hlayout1_2->addStretch(100);

  groupbox1 = new QGroupBox("Colorschema");
  groupbox1->setLayout(hlayout1_2);

  QVBoxLayout *vlayout1_1 = new QVBoxLayout;
  vlayout1_1->addLayout(flayout1_1);
  vlayout1_1->addStretch(1000);

  QVBoxLayout *vlayout1_2 = new QVBoxLayout;
  vlayout1_2->addLayout(flayout1_2);
  vlayout1_2->addStretch(1000);

  QVBoxLayout *vlayout1_3 = new QVBoxLayout;
  vlayout1_3->addStretch(200);
  vlayout1_3->addWidget(groupbox1);
  vlayout1_3->addStretch(1000);

  QHBoxLayout *hlayout1_1 = new QHBoxLayout;
  hlayout1_1->addLayout(vlayout1_1);
  hlayout1_1->addSpacing(40);
  hlayout1_1->addLayout(vlayout1_2);
  hlayout1_1->addStretch(500);
  hlayout1_1->addLayout(vlayout1_3);
  hlayout1_1->addStretch(500);

  tab1->setLayout(hlayout1_1);

  QObject::connect(BgColorButton,           SIGNAL(clicked(SpecialButton *)), this, SLOT(BgColorButtonClicked(SpecialButton *)));
  QObject::connect(SrColorButton,           SIGNAL(clicked(SpecialButton *)), this, SLOT(SrColorButtonClicked(SpecialButton *)));
  QObject::connect(BrColorButton,           SIGNAL(clicked(SpecialButton *)), this, SLOT(BrColorButtonClicked(SpecialButton *)));
  QObject::connect(MrColorButton,           SIGNAL(clicked(SpecialButton *)), this, SLOT(MrColorButtonClicked(SpecialButton *)));
  QObject::connect(TxtColorButton,          SIGNAL(clicked(SpecialButton *)), this, SLOT(TxtColorButtonClicked(SpecialButton *)));
  QObject::connect(SigColorButton,          SIGNAL(clicked(SpecialButton *)), this, SLOT(SigColorButtonClicked(SpecialButton *)));
  QObject::connect(BaseColorButton,         SIGNAL(clicked(SpecialButton *)), this, SLOT(BaseColorButtonClicked(SpecialButton *)));
  QObject::connect(Crh1ColorButton,         SIGNAL(clicked(SpecialButton *)), this, SLOT(Crh1ColorButtonClicked(SpecialButton *)));
  QObject::connect(Crh2ColorButton,         SIGNAL(clicked(SpecialButton *)), this, SLOT(Crh2ColorButtonClicked(SpecialButton *)));
  QObject::connect(FrColorButton,           SIGNAL(clicked(SpecialButton *)), this, SLOT(FrColorButtonClicked(SpecialButton *)));
  QObject::connect(AnnotMkrButton,          SIGNAL(clicked(SpecialButton *)), this, SLOT(AnnotMkrButtonClicked(SpecialButton *)));
  QObject::connect(AnnotDurationButton,     SIGNAL(clicked(SpecialButton *)), this, SLOT(AnnotDurationButtonClicked(SpecialButton *)));
  QObject::connect(AnnotDurationSelectedButton,     SIGNAL(clicked(SpecialButton *)), this, SLOT(AnnotDurationSelectedButtonClicked(SpecialButton *)));
  QObject::connect(checkbox1,               SIGNAL(stateChanged(int)),        this, SLOT(checkbox1Clicked(int)));
  QObject::connect(checkbox2,               SIGNAL(stateChanged(int)),        this, SLOT(checkbox2Clicked(int)));
  QObject::connect(checkbox2_1,             SIGNAL(stateChanged(int)),        this, SLOT(checkbox2_1Clicked(int)));
  QObject::connect(checkbox2_2,             SIGNAL(stateChanged(int)),        this, SLOT(checkbox2_2Clicked(int)));
  QObject::connect(checkbox3,               SIGNAL(stateChanged(int)),        this, SLOT(checkbox3Clicked(int)));
  QObject::connect(checkbox4,               SIGNAL(stateChanged(int)),        this, SLOT(checkbox4Clicked(int)));
  QObject::connect(checkbox5,               SIGNAL(stateChanged(int)),        this, SLOT(checkbox5Clicked(int)));
  QObject::connect(checkbox16,              SIGNAL(stateChanged(int)),        this, SLOT(checkbox16Clicked(int)));
  QObject::connect(saveColorSchemaButton,   SIGNAL(clicked()),                this, SLOT(saveColorSchemaButtonClicked()));
  QObject::connect(loadColorSchemaButton,   SIGNAL(clicked()),                this, SLOT(loadColorSchemaButtonClicked()));
  QObject::connect(colorSchema_Blue_on_Gray_Button, SIGNAL(clicked()),        this, SLOT(loadColorSchema_blue_gray()));
  QObject::connect(colorSchema_NK_Button,   SIGNAL(clicked()),                this, SLOT(loadColorSchema_NK()));
  QObject::connect(colorSchema_Dark_Button, SIGNAL(clicked()),                this, SLOT(loadColorSchema_Dark()));

  tabholder->addTab(tab1, "Colors");

/////////////////////////////////////// tab 2 Calibration ///////////////////////////////////////////////////////////////////////

  tab2 = new QWidget;

  checkbox2_1 = new QCheckBox("Manually override automatic DPI settings");
  checkbox2_1->setTristate(false);
  if(mainwindow->auto_dpi)
  {
    checkbox2_1->setCheckState(Qt::Unchecked);
  }
  else
  {
    checkbox2_1->setCheckState(Qt::Checked);
  }

  slabel2_1 = new SpecialButton;
  slabel2_1->setMinimumSize(10, 445);
  slabel2_1->setMaximumSize(10, 445);
  slabel2_1->setColor(Qt::black);

  slabel2_3 = new SpecialButton;
  slabel2_3->setMinimumSize(355, 10);
  slabel2_3->setMaximumSize(355, 10);
  slabel2_3->setColor(Qt::black);

  QLabel *label2_2 = new QLabel("Measure the length of the black\nrectangles and enter the values.");

  spinbox2_1 = new QSpinBox;
  spinbox2_1->setSuffix(" mm");
  spinbox2_1->setMinimum(10);
  spinbox2_1->setMaximum(500);
  spinbox2_1->setValue((int)(4450 * mainwindow->y_pixelsizefactor));

  spinbox2_2 = new QSpinBox;
  spinbox2_2->setSuffix(" mm");
  spinbox2_2->setMinimum(10);
  spinbox2_2->setMaximum(500);
  spinbox2_2->setValue((int)(3550 * mainwindow->x_pixelsizefactor));

  ApplyButton = new QPushButton;
  ApplyButton->setText("Apply");

  if(checkbox2_1->checkState() == Qt::Unchecked)
  {
    spinbox2_1->setEnabled(false);
    spinbox2_2->setEnabled(false);
    ApplyButton->setEnabled(false);
  }

  QVBoxLayout *vlayout2_1 = new QVBoxLayout;
  vlayout2_1->addWidget(slabel2_1);
  vlayout2_1->addStretch(1000);

  QHBoxLayout *hlayout2_2 = new QHBoxLayout;
  hlayout2_2->addWidget(label2_2);
  hlayout2_2->addStretch(1000);

  QHBoxLayout *hlayout2_3 = new QHBoxLayout;
  hlayout2_3->addWidget(spinbox2_1);
  hlayout2_3->addStretch(1000);

  QHBoxLayout *hlayout2_4 = new QHBoxLayout;
  hlayout2_4->addWidget(slabel2_3);
  hlayout2_4->addStretch(1000);

  QHBoxLayout *hlayout2_5 = new QHBoxLayout;
  hlayout2_5->addWidget(spinbox2_2);
  hlayout2_5->addStretch(1000);

  QHBoxLayout *hlayout2_6 = new QHBoxLayout;
  hlayout2_6->addWidget(checkbox2_1);
  hlayout2_6->addStretch(1000);

  QHBoxLayout *hlayout2_7 = new QHBoxLayout;
  hlayout2_7->addWidget(ApplyButton);
  hlayout2_7->addStretch(1000);

  QVBoxLayout *vlayout2_2 = new QVBoxLayout;
  vlayout2_2->addStretch(100);
  vlayout2_2->addLayout(hlayout2_2);
  vlayout2_2->addStretch(100);
  vlayout2_2->addLayout(hlayout2_3);
  vlayout2_2->addStretch(200);
  vlayout2_2->addLayout(hlayout2_4);
  vlayout2_2->addLayout(hlayout2_5);
  vlayout2_2->addStretch(200);
  vlayout2_2->addLayout(hlayout2_6);
  vlayout2_2->addStretch(200);
  vlayout2_2->addLayout(hlayout2_7);
  vlayout2_2->addStretch(500);

  QHBoxLayout *hlayout2_1 = new QHBoxLayout;
  hlayout2_1->addSpacing(20);
  hlayout2_1->addLayout(vlayout2_1);
  hlayout2_1->addSpacing(20);
  hlayout2_1->addLayout(vlayout2_2);
  hlayout2_1->addStretch(1000);

  tab2->setLayout(hlayout2_1);

  QObject::connect(ApplyButton, SIGNAL(clicked()),         this, SLOT(ApplyButtonClicked()));
  QObject::connect(checkbox2_1, SIGNAL(stateChanged(int)), this, SLOT(calibrate_checkbox_stateChanged(int)));

  tabholder->addTab(tab2, "Calibration");

/////////////////////////////////////// tab 3 Powerspectrum ///////////////////////////////////////////////////////////////////////

  tab3 = new QWidget;

  QLabel *label3_1 = new QLabel("Frequency regions of the colorbars:");

  colorBarTable = new QTableWidget;
  colorBarTable->setSelectionMode(QAbstractItemView::NoSelection);
  colorBarTable->setColumnCount(4);
  colorBarTable->setRowCount(MAXSPECTRUMMARKERS);
  for(i=0; i < MAXSPECTRUMMARKERS; i++)
  {
    colorBarTable->setCellWidget(i, 0, new QCheckBox);
   ((QCheckBox *)(colorBarTable->cellWidget(i, 0)))->setTristate(false);
    if(i < mainwindow->spectrum_colorbar->items)
    {
      ((QCheckBox *)(colorBarTable->cellWidget(i, 0)))->setCheckState(Qt::Checked);
    }
    else
    {
      ((QCheckBox *)(colorBarTable->cellWidget(i, 0)))->setCheckState(Qt::Unchecked);
    }
    QObject::connect(colorBarTable->cellWidget(i, 0), SIGNAL(stateChanged(int)), this, SLOT(checkBoxChanged(int)));

    colorBarTable->setCellWidget(i, 1, new QDoubleSpinBox);
    ((QDoubleSpinBox *)(colorBarTable->cellWidget(i, 1)))->setDecimals(3);
    ((QDoubleSpinBox *)(colorBarTable->cellWidget(i, 1)))->setSuffix(" Hz");
    ((QDoubleSpinBox *)(colorBarTable->cellWidget(i, 1)))->setRange(0.001, 100000.0);
    ((QDoubleSpinBox *)(colorBarTable->cellWidget(i, 1)))->setValue(mainwindow->spectrum_colorbar->freq[i]);
    QObject::connect((QDoubleSpinBox *)(colorBarTable->cellWidget(i, 1)), SIGNAL(valueChanged(double)), this, SLOT(spinBoxValueChanged(double)));

    colorBarTable->setCellWidget(i, 2, new SpecialButton);
    ((SpecialButton *)(colorBarTable->cellWidget(i, 2)))->setGlobalColor(mainwindow->spectrum_colorbar->color[i]);
    QObject::connect((SpecialButton *)(colorBarTable->cellWidget(i, 2)), SIGNAL(clicked(SpecialButton *)), this, SLOT(colorBarButtonClicked(SpecialButton *)));

    colorBarTable->setCellWidget(i, 3, new QLineEdit);
    ((QLineEdit *)(colorBarTable->cellWidget(i, 3)))->setText(mainwindow->spectrum_colorbar->label[i]);
    ((QLineEdit *)(colorBarTable->cellWidget(i, 3)))->setMaxLength(16);
    QObject::connect((QLineEdit *)(colorBarTable->cellWidget(i, 3)), SIGNAL(textEdited(const QString  &)), this, SLOT(labelEdited(const QString  &)));
  }

  QStringList horizontallabels;
  horizontallabels += "";
  horizontallabels += "Frequency";
  horizontallabels += "Color";
  horizontallabels += "Label";
  colorBarTable->setHorizontalHeaderLabels(horizontallabels);

  colorBarTable->resizeColumnsToContents();

  QLabel *label3_2 = new QLabel("Height of colorbars are relative to the");

  radiobutton1 = new QRadioButton;
  radiobutton1->setText("sum");
  if(mainwindow->spectrum_colorbar->method == 0)
  {
    radiobutton1->setChecked(true);  // sum
  }

  radiobutton2 = new QRadioButton;
  radiobutton2->setText("peak");
  if(mainwindow->spectrum_colorbar->method == 1)
  {
    radiobutton2->setChecked(true);  // peak
  }

  radiobutton3 = new QRadioButton;
  radiobutton3->setText("average");
  if(mainwindow->spectrum_colorbar->method == 2)
  {
    radiobutton3->setChecked(true);  // average
  }

  QLabel *label3_3 = new QLabel("of the power in the colorbar region.");

  QFormLayout *flayout3_1 = new QFormLayout;
  flayout3_1->setSpacing(20);

  spinbox3_1 = new QSpinBox;
  spinbox3_1->setSuffix(" samples");
  spinbox3_1->setMinimum(10);
  spinbox3_1->setMaximum(1000);
  spinbox3_1->setSingleStep(2);
  spinbox3_1->setValue(mainwindow->maxdftblocksize);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(spinbox3_1);
  hlayout_tmp->addStretch(1000);
  flayout3_1->addRow("FFT blocksize:", hlayout_tmp);

  dspinbox3_2 = new QDoubleSpinBox;
  dspinbox3_2->setMinimum(0.0001);
  dspinbox3_2->setMaximum(100000.0);
  dspinbox3_2->setValue(mainwindow->spectrum_colorbar->max_colorbar_value);
  checkbox3_1 = new QCheckBox("Auto");
  checkbox3_1->setTristate(false);
  if(mainwindow->spectrum_colorbar->auto_adjust)
  {
    checkbox3_1->setCheckState(Qt::Checked);

    dspinbox3_2->setEnabled(false);
  }
  else
  {
    checkbox3_1->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(dspinbox3_2);
  hlayout_tmp->addSpacing(20);
  hlayout_tmp->addWidget(checkbox3_1);
  hlayout_tmp->addStretch(1000);
  flayout3_1->addRow("Colorbar sensitivity:", hlayout_tmp);

  QHBoxLayout *hlayout3_3 = new QHBoxLayout;
  hlayout3_3->addWidget(label3_2);
  hlayout3_3->addStretch(1000);

  QHBoxLayout *hlayout3_4 = new QHBoxLayout;
  hlayout3_4->addWidget(radiobutton1);
  hlayout3_4->addStretch(1000);

  QHBoxLayout *hlayout3_5 = new QHBoxLayout;
  hlayout3_5->addWidget(radiobutton2);
  hlayout3_5->addStretch(1000);

  QHBoxLayout *hlayout3_6 = new QHBoxLayout;
  hlayout3_6->addWidget(radiobutton3);
  hlayout3_6->addStretch(1000);

  QHBoxLayout *hlayout3_7 = new QHBoxLayout;
  hlayout3_7->addWidget(label3_3);
  hlayout3_7->addStretch(1000);

  DefaultButton2 = new QPushButton;
  DefaultButton2->setText("Restore default");

  ApplyButton2 = new QPushButton;
  ApplyButton2->setText("Apply");
  ApplyButton2->setEnabled(false);

  QHBoxLayout *hlayout3_2 = new QHBoxLayout;
  hlayout3_2->addWidget(ApplyButton2);
  hlayout3_2->addSpacing(20);
  hlayout3_2->addStretch(500);
  hlayout3_2->addWidget(DefaultButton2);
  hlayout3_2->addStretch(500);

  QVBoxLayout *vlayout3_1 = new QVBoxLayout;
  vlayout3_1->addWidget(label3_1);
  vlayout3_1->addWidget(colorBarTable, 1000);

  QVBoxLayout *vlayout3_2 = new QVBoxLayout;
  vlayout3_2->addSpacing(40);
  vlayout3_2->addLayout(hlayout3_3);
  vlayout3_2->addLayout(hlayout3_4);
  vlayout3_2->addLayout(hlayout3_5);
  vlayout3_2->addLayout(hlayout3_6);
  vlayout3_2->addLayout(hlayout3_7);
  vlayout3_2->addSpacing(40);
  vlayout3_2->addLayout(flayout3_1);
  vlayout3_2->addStretch(1000);
  vlayout3_2->addLayout(hlayout3_2);

  QHBoxLayout *hlayout3_1 = new QHBoxLayout;
  hlayout3_1->addLayout(vlayout3_1, 1000);
  hlayout3_1->addSpacing(20);
  hlayout3_1->addLayout(vlayout3_2);

  tab3->setLayout(hlayout3_1);

  QObject::connect(radiobutton1,   SIGNAL(toggled(bool)),        this, SLOT(radioButtonToggled(bool)));
  QObject::connect(radiobutton2,   SIGNAL(toggled(bool)),        this, SLOT(radioButtonToggled(bool)));
  QObject::connect(radiobutton3,   SIGNAL(toggled(bool)),        this, SLOT(radioButtonToggled(bool)));
  QObject::connect(spinbox3_1,     SIGNAL(valueChanged(int)),    this, SLOT(spinBox3_1ValueChanged(int)));
  QObject::connect(dspinbox3_2,    SIGNAL(valueChanged(double)), this, SLOT(dspinBox3_2ValueChanged(double)));
  QObject::connect(ApplyButton2,   SIGNAL(clicked()),            this, SLOT(ApplyButton2Clicked()));
  QObject::connect(DefaultButton2, SIGNAL(clicked()),            this, SLOT(DefaultButton2Clicked()));
  QObject::connect(checkbox3_1,    SIGNAL(stateChanged(int)),    this, SLOT(checkbox3_1Clicked(int)));

  tabholder->addTab(tab3, "Power Spectrum");

/////////////////////////////////////// tab 4 Other ///////////////////////////////////////////////////////////////////////

  tab4 = new QWidget;

  QFormLayout *flayout4_1 = new QFormLayout;
  flayout4_1->setSpacing(20);

  checkbox4_1 = new QCheckBox;
  checkbox4_1->setTristate(false);
  if(mainwindow->auto_reload_mtg)
  {
    checkbox4_1->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox4_1->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox4_1);
  hlayout_tmp->addStretch(1000);
  flayout4_1->addRow("Reload last used montage", hlayout_tmp);
  QObject::connect(checkbox4_1, SIGNAL(stateChanged(int)), this, SLOT(checkbox4_1Clicked(int)));

  spinbox4_3 = new QSpinBox;
  spinbox4_3->setSuffix(" MB");
  spinbox4_3->setMinimum(100);
  spinbox4_3->setMaximum(100000);
  spinbox4_3->setSingleStep(1);
  spinbox4_3->setValue((int)(mainwindow->maxfilesize_to_readin_annotations / 1048576LL));
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(spinbox4_3);
  hlayout_tmp->addStretch(1000);
  flayout4_1->addRow("Do not read annotations, Biosemi Status signal\n"
                    "or Nihon Kohden triggers when filesize\n"
                    "is more than:", hlayout_tmp);
  QObject::connect(spinbox4_3, SIGNAL(valueChanged(int)), this, SLOT(spinBox4_3ValueChanged(int)));

  checkbox4_2 = new QCheckBox;
  checkbox4_2->setTristate(false);
  if(mainwindow->read_biosemi_status_signal)
  {
    checkbox4_2->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox4_2->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox4_2);
  hlayout_tmp->addStretch(1000);
  flayout4_1->addRow("Read Biosemi Status signal", hlayout_tmp);
  QObject::connect(checkbox4_2, SIGNAL(stateChanged(int)), this, SLOT(checkbox4_2Clicked(int)));

  checkbox4_3 = new QCheckBox;
  checkbox4_3->setTristate(false);
  if(mainwindow->read_nk_trigger_signal)
  {
    checkbox4_3->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox4_3->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox4_3);
  hlayout_tmp->addStretch(1000);
  flayout4_1->addRow("Read Nihon Kohden Trigger/Marker signal", hlayout_tmp);
  QObject::connect(checkbox4_3, SIGNAL(stateChanged(int)), this, SLOT(checkbox4_3Clicked(int)));

  spinbox4_1 = new QSpinBox;
  spinbox4_1->setSuffix(" mSec");
  spinbox4_1->setMinimum(100);
  spinbox4_1->setMaximum(3000);
  spinbox4_1->setSingleStep(1);
  spinbox4_1->setValue(mainwindow->live_stream_update_interval);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(spinbox4_1);
  hlayout_tmp->addStretch(1000);
  flayout4_1->addRow("livestream update interval", hlayout_tmp);
  QObject::connect(spinbox4_1, SIGNAL(valueChanged(int)), this, SLOT(spinBox4_1ValueChanged(int)));

  combobox4_1 = new QComboBox;
  combobox4_1->addItem("50 Hz");
  combobox4_1->addItem("60 Hz");
  if(mainwindow->powerlinefreq == 50)
  {
    combobox4_1->setCurrentIndex(0);
  }
  if(mainwindow->powerlinefreq == 60)
  {
    combobox4_1->setCurrentIndex(1);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(combobox4_1);
  hlayout_tmp->addStretch(1000);
  flayout4_1->addRow("Powerline Frequency", hlayout_tmp);
  QObject::connect(combobox4_1, SIGNAL(currentIndexChanged(int)), this, SLOT(combobox4_1IndexChanged(int)));

  spinbox4_2 = new QSpinBox;
  spinbox4_2->setPrefix("Timescale / ");
  spinbox4_2->setMinimum(0);
  spinbox4_2->setMaximum(100);
  spinbox4_2->setSingleStep(1);
  spinbox4_2->setValue(mainwindow->mousewheelsens);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(spinbox4_2);
  hlayout_tmp->addStretch(1000);
  flayout4_1->addRow("Mousewheel stepsize\n"
                     "(0 is no scroll)", hlayout_tmp);
  QObject::connect(spinbox4_2, SIGNAL(valueChanged(int)), this, SLOT(spinBox4_2ValueChanged(int)));

  checkbox4_4 = new QCheckBox;
  checkbox4_4->setTristate(false);
  if(mainwindow->use_threads)
  {
    checkbox4_4->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox4_4->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox4_4);
  hlayout_tmp->addStretch(1000);
  flayout4_1->addRow("Use Multi-Threading", hlayout_tmp);
  QObject::connect(checkbox4_4, SIGNAL(stateChanged(int)), this, SLOT(checkbox4_4Clicked(int)));

  QFormLayout *flayout4_2 = new QFormLayout;
  flayout4_2->setSpacing(20);

  checkbox4_5 = new QCheckBox;
  checkbox4_5->setTristate(false);
  if(mainwindow->check_for_updates)
  {
    checkbox4_5->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox4_5->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox4_5);
  hlayout_tmp->addStretch(1000);
  flayout4_2->addRow("Check for updates during startup", hlayout_tmp);
  QObject::connect(checkbox4_5, SIGNAL(stateChanged(int)), this, SLOT(checkbox4_5Clicked(int)));

  combobox4_2 = new QComboBox;
  combobox4_2->addItem("relative");
  combobox4_2->addItem("real (relative)");
  combobox4_2->addItem("date real (relative)");
  combobox4_2->setCurrentIndex(mainwindow->viewtime_indicator_type);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(combobox4_2);
  hlayout_tmp->addStretch(1000);
  flayout4_2->addRow("Viewtime / fileposition indicator", hlayout_tmp);
  QObject::connect(combobox4_2, SIGNAL(currentIndexChanged(int)), this, SLOT(combobox4_2IndexChanged(int)));

  combobox4_3 = new QComboBox;
  combobox4_3->addItem("Subject info");
  combobox4_3->addItem("Filename");
  combobox4_3->addItem("Filename with full path");
  combobox4_3->setCurrentIndex(mainwindow->mainwindow_title_type);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(combobox4_3);
  hlayout_tmp->addStretch(1000);
  flayout4_2->addRow("Window title content", hlayout_tmp);
  QObject::connect(combobox4_3, SIGNAL(currentIndexChanged(int)), this, SLOT(combobox4_3IndexChanged(int)));

  dspinbox4_4 = new QDoubleSpinBox;
  dspinbox4_4->setMinimum(0.001);
  dspinbox4_4->setMaximum(10000000);
  dspinbox4_4->setSuffix(" /cm");
  dspinbox4_4->setValue(mainwindow->default_amplitude);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(dspinbox4_4);
  hlayout_tmp->addStretch(1000);
  flayout4_2->addRow("Default amplitude", hlayout_tmp);
  QObject::connect(dspinbox4_4, SIGNAL(valueChanged(double)), this, SLOT(dspinbox4_4ValueChanged(double)));

  checkbox4_6 = new QCheckBox;
  checkbox4_6->setTristate(false);
  checkbox4_6->setToolTip("Enabling this option will avoid the \"stairstep\" effect and will make the signal look smoother.");
  if(mainwindow->linear_interpol)
  {
    checkbox4_6->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox4_6->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox4_6);
  hlayout_tmp->addStretch(1000);
  flayout4_2->addRow("Use linear interpolation for plotting", hlayout_tmp);
  QObject::connect(checkbox4_6, SIGNAL(stateChanged(int)), this, SLOT(checkbox4_6Clicked(int)));

  checkbox4_7 = new QCheckBox;
  checkbox4_7->setTristate(false);
  checkbox4_7->setToolTip("Enabling this option will automatically update the onsettime field of the annotation-editor\n"
                          "when scrolling and a cross-hair is active.");
  if(mainwindow->auto_update_annot_onset)
  {
    checkbox4_7->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox4_7->setCheckState(Qt::Unchecked);
  }
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(checkbox4_7);
  hlayout_tmp->addStretch(1000);
  flayout4_2->addRow("Auto update annotation-editor onsettime", hlayout_tmp);
  QObject::connect(checkbox4_7, SIGNAL(stateChanged(int)), this, SLOT(checkbox4_7Clicked(int)));

  lineedit4_1 = new QLineEdit;
  lineedit4_1->setMaxLength(31);
  lineedit4_1->setText(mainwindow->ecg_qrs_rpeak_descr);
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(lineedit4_1);
  hlayout_tmp->addStretch(1000);
  flayout4_2->addRow("R-wave description string", hlayout_tmp);
  QObject::connect(lineedit4_1, SIGNAL(textEdited(const QString)), this, SLOT(lineedit4_1_changed(const QString)));

  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addLayout(flayout4_1);
  hlayout_tmp->addSpacing(20);
  hlayout_tmp->addStretch(300);
  hlayout_tmp->addLayout(flayout4_2);
  hlayout_tmp->addStretch(1000);

  vlayout_tmp = new QVBoxLayout;
  vlayout_tmp->addLayout(hlayout_tmp);
  vlayout_tmp->addStretch(1000);

  tab4->setLayout(vlayout_tmp);

  tabholder->addTab(tab4, "Other");

/////////////////////////////////////// tab 5 Font ///////////////////////////////////////////////////////////////////////

  tab5 = new QWidget;

  QFormLayout *flayout5_1 = new QFormLayout;
  flayout5_1->setSpacing(20);

  spinbox5_1 = new QSpinBox;
  spinbox5_1->setRange(8, 24);
  spinbox5_1->setValue(mainwindow->font_size);
  textEdit5_1 = new QTextEdit;
  textEdit5_1->setPlainText("The quick brown fox jumps over the lazy dog. 0123456789 AaBbYyZz");
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(spinbox5_1);
  hlayout_tmp->addWidget(textEdit5_1, 500);
  hlayout_tmp->addStretch(500);
  flayout5_1->addRow("Font size", hlayout_tmp);

  spinbox5_2 = new QSpinBox;
  spinbox5_2->setRange(8, 24);
  spinbox5_2->setValue(mainwindow->monofont_size);
  textEdit5_2 = new QTextEdit;
  textEdit5_2->setFont(*mainwindow->monofont);
  textEdit5_2->setPlainText("The quick brown fox jumps over the lazy dog. 0123456789 AaBbYyZz");
  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(spinbox5_2);
  hlayout_tmp->addWidget(textEdit5_2, 500);
  hlayout_tmp->addStretch(500);
  flayout5_1->addRow("Monofont size", hlayout_tmp);

  DefaultButton5 = new QPushButton;
  DefaultButton5->setText("System default");

  ApplyButton5 = new QPushButton;
  ApplyButton5->setText("Apply");
  ApplyButton5->setEnabled(false);

  hlayout_tmp = new QHBoxLayout;
  hlayout_tmp->addWidget(ApplyButton5);
  hlayout_tmp->addStretch(500);
  hlayout_tmp->addWidget(DefaultButton5);
  hlayout_tmp->addStretch(1000);

  vlayout_tmp = new QVBoxLayout;
  vlayout_tmp->addStretch(1000);
  vlayout_tmp->addLayout(flayout5_1);
  vlayout_tmp->addStretch(1000);
  vlayout_tmp->addLayout(hlayout_tmp);

  tab5->setLayout(vlayout_tmp);

  tabholder->addTab(tab5, "Font");

  QObject::connect(spinbox5_1,     SIGNAL(valueChanged(int)), this, SLOT(spinBox5_1ValueChanged(int)));
  QObject::connect(spinbox5_2,     SIGNAL(valueChanged(int)), this, SLOT(spinBox5_2ValueChanged(int)));
  QObject::connect(ApplyButton5,   SIGNAL(clicked()),         this, SLOT(ApplyButton5Clicked()));
  QObject::connect(DefaultButton5, SIGNAL(clicked()),         this, SLOT(DefaultButton5Clicked()));

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  QHBoxLayout *horLayout = new QHBoxLayout;
  horLayout->addStretch(1000);
  horLayout->addWidget(CloseButton);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(tabholder);
  mainLayout->addSpacing(20);
  mainLayout->addLayout(horLayout);

  optionsdialog->setMinimumSize(900 * mainwindow->w_scaling, 575 * mainwindow->h_scaling);

  optionsdialog->setLayout(mainLayout);

  QObject::connect(CloseButton, SIGNAL(clicked()), optionsdialog, SLOT(close()));

  optionsdialog->exec();
}


void UI_OptionsDialog::spinBox4_3ValueChanged(int filesize)
{
  mainwindow->maxfilesize_to_readin_annotations = (long long)filesize * 1048576LL;
}


void UI_OptionsDialog::spinBox4_2ValueChanged(int stepsize)
{
  mainwindow->mousewheelsens = stepsize;
}


void UI_OptionsDialog::combobox4_1IndexChanged(int index)
{
  if(index == 0)
  {
    mainwindow->powerlinefreq = 50;
  }

  if(index == 1)
  {
    mainwindow->powerlinefreq = 60;
  }
}


void UI_OptionsDialog::combobox4_2IndexChanged(int index)
{
  mainwindow->viewtime_indicator_type = index;

  mainwindow->setup_viewbuf();
}


void UI_OptionsDialog::combobox4_3IndexChanged(int index)
{
  mainwindow->mainwindow_title_type = index;

  mainwindow->setMainwindowTitle(mainwindow->edfheaderlist[mainwindow->sel_viewtime]);
}


void UI_OptionsDialog::spinBox4_1ValueChanged(int interval)
{
  mainwindow->live_stream_update_interval = interval;
}


void UI_OptionsDialog::calibrate_checkbox_stateChanged(int state)
{
  if(state == Qt::Checked)
  {
    spinbox2_1->setEnabled(true);
    spinbox2_2->setEnabled(true);
    ApplyButton->setEnabled(true);
    mainwindow->auto_dpi = 0;
  }
  else
  {
    spinbox2_1->setEnabled(false);
    spinbox2_2->setEnabled(false);
    ApplyButton->setEnabled(false);
    mainwindow->auto_dpi = 1;
    mainwindow->y_pixelsizefactor = 2.54 / mainwindow->dpiy;
    mainwindow->x_pixelsizefactor = 2.54 / mainwindow->dpix;

    mainwindow->maincurve->drawCurve_stage_1();
  }
}


void UI_OptionsDialog::ApplyButtonClicked()
{
  int i, j;

  mainwindow->y_pixelsizefactor = spinbox2_1->value() / 4450.0;
  mainwindow->x_pixelsizefactor = spinbox2_2->value() / 3550.0;

  for(i=0; i<mainwindow->signalcomps; i++)
  {
    for(j=0; j<mainwindow->signalcomp[i]->num_of_signals; j++)
    {
      mainwindow->signalcomp[i]->sensitivity[j] =
       mainwindow->signalcomp[i]->edfhdr->edfparam[mainwindow->signalcomp[i]->edfsignal[j]].bitvalue
       / ((double)mainwindow->signalcomp[i]->voltpercm
       * mainwindow->y_pixelsizefactor);
    }
  }

  mainwindow->maincurve->drawCurve_stage_1();
}


void UI_OptionsDialog::labelEdited(const QString  &)
{
  ApplyButton2->setEnabled(true);
}


void UI_OptionsDialog::spinBox3_1ValueChanged(int)
{
  ApplyButton2->setEnabled(true);
}


void UI_OptionsDialog::dspinBox3_2ValueChanged(double)
{
  ApplyButton2->setEnabled(true);
}


void UI_OptionsDialog::radioButtonToggled(bool)
{
  ApplyButton2->setEnabled(true);
}


void UI_OptionsDialog::spinBoxValueChanged(double)
{
  ApplyButton2->setEnabled(true);
}


void UI_OptionsDialog::ApplyButton2Clicked()
{
  int i, row;

  char str[256];

  for(row = 1; row < MAXSPECTRUMMARKERS; row++)
  {
    if(((QCheckBox *)(colorBarTable->cellWidget(row, 0)))->checkState() == Qt::Checked)
    {
      if(((QDoubleSpinBox *)(colorBarTable->cellWidget(row - 1, 1)))->value() >= ((QDoubleSpinBox *)(colorBarTable->cellWidget(row, 1)))->value())
      {
        snprintf(str, 256, "Row %i must have a higher frequency than row %i", row + 1, row);

        QMessageBox messagewindow(QMessageBox::Critical, "Error", str);
        messagewindow.exec();

        return;
      }
    }
    else
    {
      break;
    }
  }

  for(row = 0; row < MAXSPECTRUMMARKERS; row++)
  {
    if(((QCheckBox *)(colorBarTable->cellWidget(row, 0)))->checkState() == Qt::Checked)
    {
      mainwindow->spectrum_colorbar->freq[row] = ((QDoubleSpinBox *)(colorBarTable->cellWidget(row, 1)))->value();
      mainwindow->spectrum_colorbar->color[row] = ((SpecialButton *)(colorBarTable->cellWidget(row, 2)))->globalColor();
      strncpy(mainwindow->spectrum_colorbar->label[row], ((QLineEdit *)(colorBarTable->cellWidget(row, 3)))->text().toLatin1().data(), 16);
      mainwindow->spectrum_colorbar->label[row][16] = 0;
    }
    else
    {
      break;
    }
  }

  mainwindow->spectrum_colorbar->items = row;

  for(; row < MAXSPECTRUMMARKERS; row++)
  {
    mainwindow->spectrum_colorbar->freq[row] = ((QDoubleSpinBox *)(colorBarTable->cellWidget(row, 1)))->value();
    mainwindow->spectrum_colorbar->color[row] = ((SpecialButton *)(colorBarTable->cellWidget(row, 2)))->globalColor();
  }

  if(radiobutton1->isChecked()) // sum
  {
    mainwindow->spectrum_colorbar->method = 0;
  }
  else
    if(radiobutton2->isChecked()) // peak
    {
      mainwindow->spectrum_colorbar->method = 1;
    }
    else
      if(radiobutton3->isChecked()) // average
      {
        mainwindow->spectrum_colorbar->method = 2;
      }

  mainwindow->maxdftblocksize = spinbox3_1->value();
  if(mainwindow->maxdftblocksize & 1)
  {
    mainwindow->maxdftblocksize--;
  }

  mainwindow->spectrum_colorbar->max_colorbar_value = dspinbox3_2->value();

  if(checkbox3_1->checkState() == Qt::Checked)
  {
    mainwindow->spectrum_colorbar->auto_adjust = 1;
  }
  else
  {
    mainwindow->spectrum_colorbar->auto_adjust = 0;
  }

  ApplyButton2->setEnabled(false);

  for(i=0; i<MAXSPECTRUMDOCKS; i++)
  {
    if(mainwindow->spectrumdock[i]->dock->isVisible())
    {
      mainwindow->spectrumdock[i]->rescan();
    }
  }
}


void UI_OptionsDialog::checkBoxChanged(int state)
{
  int i,
      row,
      lastrow=0;

  if(state == Qt::Checked)
  {
    for(row = MAXSPECTRUMMARKERS - 1; row >= 0; row--)
    {
      if(((QCheckBox *)(colorBarTable->cellWidget(row, 0)))->checkState() == Qt::Checked)
      {
        lastrow = row;

        if(row)
        {
          for(i=row-1; i>=0; i--)
          {
            ((QCheckBox *)(colorBarTable->cellWidget(i, 0)))->setCheckState(Qt::Checked);
          }
        }

        break;
      }
    }
  }
  else
  {
    for(row = 0; row < MAXSPECTRUMMARKERS; row++)
    {
      if(((QCheckBox *)(colorBarTable->cellWidget(row, 0)))->checkState() == Qt::Unchecked)
      {
        lastrow = row - 1;

        for(; row < MAXSPECTRUMMARKERS; row++)
        {
          ((QCheckBox *)(colorBarTable->cellWidget(row, 0)))->setCheckState(Qt::Unchecked);
        }

        break;
      }
    }
  }

  for(row=0; row < lastrow; row++)
  {
    if(((QDoubleSpinBox *)(colorBarTable->cellWidget(row, 1)))->value() >= ((QDoubleSpinBox *)(colorBarTable->cellWidget(row + 1, 1)))->value())
    {
      ((QDoubleSpinBox *)(colorBarTable->cellWidget(row + 1, 1)))->setValue(((QDoubleSpinBox *)(colorBarTable->cellWidget(row, 1)))->value() + 1.0);
    }
  }

  ApplyButton2->setEnabled(true);
}


void UI_OptionsDialog::DefaultButton2Clicked()
{
  int i;

  for(i=0; i<5; i++)
  {
    ((QCheckBox *)(colorBarTable->cellWidget(i, 0)))->setCheckState(Qt::Checked);
    ((QLineEdit *)(colorBarTable->cellWidget(i, 3)))->clear();
  }

  ((QDoubleSpinBox *)(colorBarTable->cellWidget(0, 1)))->setValue(4.0);
  ((SpecialButton *)(colorBarTable->cellWidget(0, 2)))->setGlobalColor(Qt::darkRed);

  ((QDoubleSpinBox *)(colorBarTable->cellWidget(1, 1)))->setValue(8.0);
  ((SpecialButton *)(colorBarTable->cellWidget(1, 2)))->setGlobalColor(Qt::darkGreen);

  ((QDoubleSpinBox *)(colorBarTable->cellWidget(2, 1)))->setValue(12.0);
  ((SpecialButton *)(colorBarTable->cellWidget(2, 2)))->setGlobalColor(Qt::darkBlue);

  ((QDoubleSpinBox *)(colorBarTable->cellWidget(3, 1)))->setValue(30.0);
  ((SpecialButton *)(colorBarTable->cellWidget(3, 2)))->setGlobalColor(Qt::darkCyan);

  ((QDoubleSpinBox *)(colorBarTable->cellWidget(4, 1)))->setValue(100.0);
  ((SpecialButton *)(colorBarTable->cellWidget(4, 2)))->setGlobalColor(Qt::darkMagenta);

  for(i=5; i<MAXSPECTRUMMARKERS; i++)
  {
    ((QCheckBox *)(colorBarTable->cellWidget(i, 0)))->setCheckState(Qt::Unchecked);
    ((QDoubleSpinBox *)(colorBarTable->cellWidget(i, 1)))->setValue(1.0);
    ((SpecialButton *)(colorBarTable->cellWidget(i, 2)))->setGlobalColor(Qt::white);
    ((QLineEdit *)(colorBarTable->cellWidget(i, 3)))->clear();
  }

  spinbox3_1->setValue(1000);

  radiobutton1->setChecked(true);

  ApplyButton2->setEnabled(true);
}


void UI_OptionsDialog::colorBarButtonClicked(SpecialButton *button)
{
  int color;

  UI_ColorMenuDialog colormenudialog(&color, mainwindow);

  if(color < 0)  return;

  button->setGlobalColor(color);

  ApplyButton2->setEnabled(true);
}


void UI_OptionsDialog::checkbox1Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->maincurve->blackwhite_printing = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->maincurve->blackwhite_printing = 0;
  }
}


void UI_OptionsDialog::checkbox2Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->show_annot_markers = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->show_annot_markers = 0;
  }

  mainwindow->maincurve->update();
}


void UI_OptionsDialog::checkbox2_1Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->annotations_show_duration = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->annotations_show_duration = 0;
  }

  mainwindow->maincurve->update();
}


void UI_OptionsDialog::checkbox2_2Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->annotations_duration_background_type = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->annotations_duration_background_type = 0;
  }

  mainwindow->maincurve->update();
}


void UI_OptionsDialog::checkbox3Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->show_baselines = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->show_baselines = 0;
  }

  mainwindow->maincurve->update();
}


void UI_OptionsDialog::checkbox4Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->clip_to_pane = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->clip_to_pane = 0;
  }

  mainwindow->maincurve->update();
}


void UI_OptionsDialog::checkbox5Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->annot_filter->hide_in_list_only = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->annot_filter->hide_in_list_only = 0;
  }
}


void UI_OptionsDialog::checkbox16Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->use_diverse_signal_colors = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->use_diverse_signal_colors = 0;
  }
}


void UI_OptionsDialog::checkbox3_1Clicked(int state)
{
  if(state==Qt::Checked)
  {
    dspinbox3_2->setEnabled(false);

    mainwindow->spectrum_colorbar->auto_adjust = 1;
  }

  if(state==Qt::Unchecked)
  {
    dspinbox3_2->setEnabled(true);

    mainwindow->spectrum_colorbar->auto_adjust = 0;
  }

  ApplyButton2->setEnabled(true);
}


void UI_OptionsDialog::checkbox4_1Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->auto_reload_mtg = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->auto_reload_mtg = 0;
  }
}


void UI_OptionsDialog::checkbox4_2Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->read_biosemi_status_signal = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->read_biosemi_status_signal = 0;
  }
}


void UI_OptionsDialog::checkbox4_3Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->read_nk_trigger_signal = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->read_nk_trigger_signal = 0;
  }
}


void UI_OptionsDialog::checkbox4_4Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->use_threads = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->use_threads = 0;
  }
}


void UI_OptionsDialog::checkbox4_5Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->check_for_updates = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->check_for_updates = 0;
  }
}


void UI_OptionsDialog::checkbox4_6Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->linear_interpol = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->linear_interpol = 0;
  }

  mainwindow->setup_viewbuf();
}


void UI_OptionsDialog::checkbox4_7Clicked(int state)
{
  if(state==Qt::Checked)
  {
    mainwindow->auto_update_annot_onset = 1;
  }

  if(state==Qt::Unchecked)
  {
    mainwindow->auto_update_annot_onset = 0;
  }
}


void UI_OptionsDialog::BgColorButtonClicked(SpecialButton *)
{
  int i;

  QColor temp;

  QPalette palette;

  temp = QColorDialog::getColor(mainwindow->maincurve->backgroundcolor, tab1);

  if(temp.isValid())
  {
    mainwindow->maincurve->backgroundcolor = temp;

    BgColorButton->setColor(mainwindow->maincurve->backgroundcolor);

    palette.setColor(QPalette::Text, mainwindow->maincurve->text_color);
    palette.setColor(QPalette::Base, mainwindow->maincurve->backgroundcolor);

    for(i=0; i<mainwindow->files_open; i++)
    {
      if(mainwindow->annotations_dock[i])
      {
        mainwindow->annotations_dock[i]->list->setPalette(palette);
      }
    }

    mainwindow->maincurve->update();
  }
}



void UI_OptionsDialog::SrColorButtonClicked(SpecialButton *)
{
  QColor temp;

  temp = QColorDialog::getColor(mainwindow->maincurve->small_ruler_color, tab1);

  if(temp.isValid())
  {
    mainwindow->maincurve->small_ruler_color = temp;

    SrColorButton->setColor(mainwindow->maincurve->small_ruler_color);

    mainwindow->maincurve->update();
  }
}



void UI_OptionsDialog::BrColorButtonClicked(SpecialButton *)
{
  QColor temp;

  temp = QColorDialog::getColor(mainwindow->maincurve->big_ruler_color, tab1);

  if(temp.isValid())
  {
    mainwindow->maincurve->big_ruler_color = temp;

    BrColorButton->setColor(mainwindow->maincurve->big_ruler_color);

    mainwindow->maincurve->update();
  }
}



void UI_OptionsDialog::MrColorButtonClicked(SpecialButton *)
{
  QColor temp;

  temp = QColorDialog::getColor(mainwindow->maincurve->mouse_rect_color, tab1);

  if(temp.isValid())
  {
    mainwindow->maincurve->mouse_rect_color = temp;

    MrColorButton->setColor(mainwindow->maincurve->mouse_rect_color);

    mainwindow->maincurve->update();
  }
}



void UI_OptionsDialog::TxtColorButtonClicked(SpecialButton *)
{
  int i;

  QColor temp;

  QPalette palette;

  temp = QColorDialog::getColor(mainwindow->maincurve->text_color, tab1);

  if(temp.isValid())
  {
    mainwindow->maincurve->text_color = temp;

    TxtColorButton->setColor(mainwindow->maincurve->text_color);

    palette.setColor(QPalette::Text, mainwindow->maincurve->text_color);
    palette.setColor(QPalette::Base, mainwindow->maincurve->backgroundcolor);

    for(i=0; i<mainwindow->files_open; i++)
    {
      if(edfplus_annotation_size(&mainwindow->edfheaderlist[i]->annot_list) > 0)
      {
        mainwindow->annotations_dock[i]->list->setPalette(palette);
      }
    }

    mainwindow->maincurve->update();
  }
}



void UI_OptionsDialog::SigColorButtonClicked(SpecialButton *)
{
  int i, color;

  UI_ColorMenuDialog colormenudialog(&color, mainwindow);

  if(color < 0)  return;

  SigColorButton->setColor((Qt::GlobalColor)color);

  mainwindow->maincurve->signal_color = color;

  for(i=0; i<mainwindow->signalcomps; i++)
  {
    mainwindow->signalcomp[i]->color = color;
  }

  mainwindow->maincurve->update();
}



void UI_OptionsDialog::BaseColorButtonClicked(SpecialButton *)
{
  QColor temp;

  temp = QColorDialog::getColor(mainwindow->maincurve->baseline_color, tab1);

  if(temp.isValid())
  {
    mainwindow->maincurve->baseline_color = temp;

    BaseColorButton->setColor(mainwindow->maincurve->baseline_color);

    mainwindow->maincurve->update();
  }
}



void UI_OptionsDialog::Crh1ColorButtonClicked(SpecialButton *)
{
  int color;

  UI_ColorMenuDialog colormenudialog(&color, mainwindow);

  if(color < 0)  return;

  Crh1ColorButton->setColor((Qt::GlobalColor)color);

  mainwindow->maincurve->crosshair_1.color = color;

  mainwindow->maincurve->update();
}



void UI_OptionsDialog::Crh2ColorButtonClicked(SpecialButton *)
{
  int color;

  UI_ColorMenuDialog colormenudialog(&color, mainwindow);

  if(color < 0)  return;

  Crh2ColorButton->setColor((Qt::GlobalColor)color);

  mainwindow->maincurve->crosshair_2.color = color;

  mainwindow->maincurve->update();
}


void UI_OptionsDialog::FrColorButtonClicked(SpecialButton *)
{
  int color;

  UI_ColorMenuDialog colormenudialog(&color, mainwindow);

  if(color < 0)  return;

  FrColorButton->setColor((Qt::GlobalColor)color);

  mainwindow->maincurve->floating_ruler_color = color;

  mainwindow->maincurve->update();
}


void UI_OptionsDialog::AnnotMkrButtonClicked(SpecialButton *)
{
  QColor temp;

  temp = QColorDialog::getColor(mainwindow->maincurve->annot_marker_color, tab1);

  if(temp.isValid())
  {
    mainwindow->maincurve->annot_marker_color = temp;

    AnnotMkrButton->setColor(mainwindow->maincurve->annot_marker_color);

    mainwindow->maincurve->update();
  }
}


void UI_OptionsDialog::AnnotDurationButtonClicked(SpecialButton *)
{
  QColor temp;

  temp = QColorDialog::getColor(mainwindow->maincurve->annot_duration_color, tab1, "Select Color", QColorDialog::ShowAlphaChannel);

  if(temp.isValid())
  {
    mainwindow->maincurve->annot_duration_color = temp;

    AnnotDurationButton->setColor(mainwindow->maincurve->annot_duration_color);

    mainwindow->maincurve->update();
  }
}


void UI_OptionsDialog::AnnotDurationSelectedButtonClicked(SpecialButton *)
{
  QColor temp;

  temp = QColorDialog::getColor(mainwindow->maincurve->annot_duration_color_selected, tab1, "Select Color", QColorDialog::ShowAlphaChannel);

  if(temp.isValid())
  {
    mainwindow->maincurve->annot_duration_color_selected = temp;

    AnnotDurationSelectedButton->setColor(mainwindow->maincurve->annot_duration_color_selected);

    mainwindow->maincurve->update();
  }
}


void UI_OptionsDialog::dspinbox4_4ValueChanged(double val)
{
  mainwindow->default_amplitude = val;
}


void UI_OptionsDialog::saveColorSchemaButtonClicked()
{
  char path[MAX_PATH_LENGTH];

  FILE *colorfile;

  strlcpy(path, mainwindow->recent_colordir, MAX_PATH_LENGTH);
  strlcat(path, "/my_colorschema.color", MAX_PATH_LENGTH);

  strlcpy(path, QFileDialog::getSaveFileName(0, "Save colorschema", QString::fromLocal8Bit(path), "Colorschema files (*.color *.COLOR)").toLocal8Bit().data(), MAX_PATH_LENGTH);

  if(!strcmp(path, ""))
  {
    return;
  }

  if(strlen(path) > 4)
  {
    if(strcmp(path + strlen(path) - 6, ".color"))
    {
      strlcat(path, ".color", MAX_PATH_LENGTH);
    }
  }

  get_directory_from_path(mainwindow->recent_colordir, path, MAX_PATH_LENGTH);

  colorfile = fopen(path, "wb");
  if(colorfile==NULL)
  {
    QMessageBox messagewindow(QMessageBox::Critical, "Error", "Can not open file for writing.");
    messagewindow.exec();

    return;
  }

  fprintf(colorfile, "<?xml version=\"1.0\"?>\n<" PROGRAM_NAME "_colorschema>\n");

  fprintf(colorfile, " <backgroundcolor>\n"
                  "  <red>%i</red>\n"
                  "  <green>%i</green>\n"
                  "  <blue>%i</blue>\n"
                  " </backgroundcolor>\n",
                  mainwindow->maincurve->backgroundcolor.red(),
                  mainwindow->maincurve->backgroundcolor.green(),
                  mainwindow->maincurve->backgroundcolor.blue());

  fprintf(colorfile, " <small_ruler_color>\n"
                  "  <red>%i</red>\n"
                  "  <green>%i</green>\n"
                  "  <blue>%i</blue>\n"
                  " </small_ruler_color>\n",
                  mainwindow->maincurve->small_ruler_color.red(),
                  mainwindow->maincurve->small_ruler_color.green(),
                  mainwindow->maincurve->small_ruler_color.blue());

  fprintf(colorfile, " <big_ruler_color>\n"
                  "  <red>%i</red>\n"
                  "  <green>%i</green>\n"
                  "  <blue>%i</blue>\n"
                  " </big_ruler_color>\n",
                  mainwindow->maincurve->big_ruler_color.red(),
                  mainwindow->maincurve->big_ruler_color.green(),
                  mainwindow->maincurve->big_ruler_color.blue());

  fprintf(colorfile, " <mouse_rect_color>\n"
                  "  <red>%i</red>\n"
                  "  <green>%i</green>\n"
                  "  <blue>%i</blue>\n"
                  " </mouse_rect_color>\n",
                  mainwindow->maincurve->mouse_rect_color.red(),
                  mainwindow->maincurve->mouse_rect_color.green(),
                  mainwindow->maincurve->mouse_rect_color.blue());

  fprintf(colorfile, " <text_color>\n"
                  "  <red>%i</red>\n"
                  "  <green>%i</green>\n"
                  "  <blue>%i</blue>\n"
                  " </text_color>\n",
                  mainwindow->maincurve->text_color.red(),
                  mainwindow->maincurve->text_color.green(),
                  mainwindow->maincurve->text_color.blue());

  fprintf(colorfile, " <baseline_color>\n"
                  "  <red>%i</red>\n"
                  "  <green>%i</green>\n"
                  "  <blue>%i</blue>\n"
                  " </baseline_color>\n",
                  mainwindow->maincurve->baseline_color.red(),
                  mainwindow->maincurve->baseline_color.green(),
                  mainwindow->maincurve->baseline_color.blue());

  fprintf(colorfile, " <annot_marker_color>\n"
                  "  <red>%i</red>\n"
                  "  <green>%i</green>\n"
                  "  <blue>%i</blue>\n"
                  " </annot_marker_color>\n",
                  mainwindow->maincurve->annot_marker_color.red(),
                  mainwindow->maincurve->annot_marker_color.green(),
                  mainwindow->maincurve->annot_marker_color.blue());

  fprintf(colorfile, " <annot_duration_color>\n"
                  "  <red>%i</red>\n"
                  "  <green>%i</green>\n"
                  "  <blue>%i</blue>\n"
                  "  <alpha>%i</alpha>\n"
                  " </annot_duration_color>\n",
                  mainwindow->maincurve->annot_duration_color.red(),
                  mainwindow->maincurve->annot_duration_color.green(),
                  mainwindow->maincurve->annot_duration_color.blue(),
                  mainwindow->maincurve->annot_duration_color.alpha());

  fprintf(colorfile, " <annot_duration_color_selected>\n"
                  "  <red>%i</red>\n"
                  "  <green>%i</green>\n"
                  "  <blue>%i</blue>\n"
                  "  <alpha>%i</alpha>\n"
                  " </annot_duration_color_selected>\n",
                  mainwindow->maincurve->annot_duration_color_selected.red(),
                  mainwindow->maincurve->annot_duration_color_selected.green(),
                  mainwindow->maincurve->annot_duration_color_selected.blue(),
                  mainwindow->maincurve->annot_duration_color_selected.alpha());

  fprintf(colorfile, " <signal_color>%i</signal_color>\n",
                  mainwindow->maincurve->signal_color);

  fprintf(colorfile, " <crosshair_1_color>%i</crosshair_1_color>\n",
                  mainwindow->maincurve->crosshair_1.color);

  fprintf(colorfile, " <crosshair_2_color>%i</crosshair_2_color>\n",
                  mainwindow->maincurve->crosshair_2.color);

  fprintf(colorfile, " <floating_ruler_color>%i</floating_ruler_color>\n",
                  mainwindow->maincurve->floating_ruler_color);

  fprintf(colorfile, " <blackwhite_printing>%i</blackwhite_printing>\n",
                  mainwindow->maincurve->blackwhite_printing);

  fprintf(colorfile, " <show_annot_markers>%i</show_annot_markers>\n",
                  mainwindow->show_annot_markers);

  fprintf(colorfile, " <show_baselines>%i</show_baselines>\n",
                  mainwindow->show_baselines);

  fprintf(colorfile, " <clip_to_pane>%i</clip_to_pane>\n",
                  mainwindow->clip_to_pane);




  fprintf(colorfile, "</" PROGRAM_NAME "_colorschema>\n");

  fclose(colorfile);
}


void UI_OptionsDialog::loadColorSchemaButtonClicked()
{
  char path[MAX_PATH_LENGTH],
       scratchpad[2048],
       result[XML_STRBUFLEN];

  struct xml_handle *xml_hdl;


  strlcpy(path, QFileDialog::getOpenFileName(0, "Load colorschema", QString::fromLocal8Bit(mainwindow->recent_colordir), "Montage files (*.color *.COLOR)").toLocal8Bit().data(), MAX_PATH_LENGTH);

  if(!strcmp(path, ""))
  {
    return;
  }

  get_directory_from_path(mainwindow->recent_colordir, path, MAX_PATH_LENGTH);

  xml_hdl = xml_get_handle(path);
  if(xml_hdl==NULL)
  {
    snprintf(scratchpad, 2048, "Can not open colorschema:\n%s", path);
    QMessageBox messagewindow(QMessageBox::Critical, "Error", QString::fromLocal8Bit(scratchpad));
    messagewindow.exec();
    return;
  }

  if(strcmp(xml_hdl->elementname[xml_hdl->level], PROGRAM_NAME "_colorschema"))
  {
    QMessageBox messagewindow(QMessageBox::Critical, "Error", "There seems to be an error in this colorschema.");
    messagewindow.exec();
    xml_close(xml_hdl);
    return;
  }

  mainwindow->get_rgbcolor_settings(xml_hdl, "backgroundcolor", 0, &mainwindow->maincurve->backgroundcolor);

  mainwindow->get_rgbcolor_settings(xml_hdl, "small_ruler_color", 0, &mainwindow->maincurve->small_ruler_color);

  mainwindow->get_rgbcolor_settings(xml_hdl, "big_ruler_color", 0, &mainwindow->maincurve->big_ruler_color);

  mainwindow->get_rgbcolor_settings(xml_hdl, "mouse_rect_color", 0, &mainwindow->maincurve->mouse_rect_color);

  mainwindow->get_rgbcolor_settings(xml_hdl, "text_color", 0, &mainwindow->maincurve->text_color);

  mainwindow->get_rgbcolor_settings(xml_hdl, "baseline_color", 0, &mainwindow->maincurve->baseline_color);

  mainwindow->get_rgbcolor_settings(xml_hdl, "annot_marker_color", 0, &mainwindow->maincurve->annot_marker_color);

  mainwindow->get_rgbcolor_settings(xml_hdl, "annot_duration_color", 0, &mainwindow->maincurve->annot_duration_color);

  mainwindow->get_rgbcolor_settings(xml_hdl, "annot_duration_color_selected", 0, &mainwindow->maincurve->annot_duration_color_selected);

  if(xml_goto_nth_element_inside(xml_hdl, "signal_color", 0))
  {
    xml_close(xml_hdl);
    return;
  }
  if(xml_get_content_of_element(xml_hdl, result, XML_STRBUFLEN))
  {
    xml_close(xml_hdl);
    return;
  }
  mainwindow->maincurve->signal_color = atoi(result);

  xml_go_up(xml_hdl);

  if(xml_goto_nth_element_inside(xml_hdl, "floating_ruler_color", 0))
  {
    xml_close(xml_hdl);
    return;
  }
  if(xml_get_content_of_element(xml_hdl, result, XML_STRBUFLEN))
  {
    xml_close(xml_hdl);
    return;
  }
  mainwindow->maincurve->floating_ruler_color = atoi(result);

  xml_go_up(xml_hdl);

  if(xml_goto_nth_element_inside(xml_hdl, "blackwhite_printing", 0))
  {
    xml_close(xml_hdl);
    return;
  }
  if(xml_get_content_of_element(xml_hdl, result, XML_STRBUFLEN))
  {
    xml_close(xml_hdl);
    return;
  }
  mainwindow->maincurve->blackwhite_printing = atoi(result);

  xml_go_up(xml_hdl);

  if(xml_goto_nth_element_inside(xml_hdl, "show_annot_markers", 0))
  {
    xml_close(xml_hdl);
    return;
  }
  if(xml_get_content_of_element(xml_hdl, result, XML_STRBUFLEN))
  {
    xml_close(xml_hdl);
    return;
  }
  mainwindow->show_annot_markers = atoi(result);

  xml_go_up(xml_hdl);

  if(xml_goto_nth_element_inside(xml_hdl, "show_baselines", 0))
  {
    xml_close(xml_hdl);
    return;
  }
  if(xml_get_content_of_element(xml_hdl, result, XML_STRBUFLEN))
  {
    xml_close(xml_hdl);
    return;
  }
  mainwindow->show_baselines = atoi(result);

  xml_go_up(xml_hdl);

  if(xml_goto_nth_element_inside(xml_hdl, "clip_to_pane", 0))
  {
    xml_close(xml_hdl);
    return;
  }
  if(xml_get_content_of_element(xml_hdl, result, XML_STRBUFLEN))
  {
    xml_close(xml_hdl);
    return;
  }
  mainwindow->clip_to_pane = atoi(result);

  xml_go_up(xml_hdl);

  if(xml_goto_nth_element_inside(xml_hdl, "crosshair_1_color", 0))
  {
    xml_close(xml_hdl);
    return;
  }
  if(xml_get_content_of_element(xml_hdl, result, XML_STRBUFLEN))
  {
    xml_close(xml_hdl);
    return;
  }
  mainwindow->maincurve->crosshair_1.color = atoi(result);

  xml_go_up(xml_hdl);

  if(xml_goto_nth_element_inside(xml_hdl, "crosshair_2_color", 0))
  {
    xml_close(xml_hdl);
    return;
  }
  if(xml_get_content_of_element(xml_hdl, result, XML_STRBUFLEN))
  {
    xml_close(xml_hdl);
    return;
  }
  mainwindow->maincurve->crosshair_2.color = atoi(result);

  xml_close(xml_hdl);

  update_interface();
}


void UI_OptionsDialog::update_interface(void)
{
  int i;

  QPalette palette;


  BgColorButton->setColor(mainwindow->maincurve->backgroundcolor);

  SrColorButton->setColor(mainwindow->maincurve->small_ruler_color);

  BrColorButton->setColor(mainwindow->maincurve->big_ruler_color);

  MrColorButton->setColor(mainwindow->maincurve->mouse_rect_color);

  TxtColorButton->setColor(mainwindow->maincurve->text_color);

  SigColorButton->setColor((Qt::GlobalColor)mainwindow->maincurve->signal_color);

  if(mainwindow->show_baselines)
  {
    checkbox3->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox3->setCheckState(Qt::Unchecked);
  }

  BaseColorButton->setColor(mainwindow->maincurve->baseline_color);

  Crh1ColorButton->setColor((Qt::GlobalColor)mainwindow->maincurve->crosshair_1.color);

  Crh2ColorButton->setColor((Qt::GlobalColor)mainwindow->maincurve->crosshair_2.color);

  FrColorButton->setColor((Qt::GlobalColor)mainwindow->maincurve->floating_ruler_color);

  if(mainwindow->show_annot_markers)
  {
    checkbox2->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox2->setCheckState(Qt::Unchecked);
  }

  AnnotMkrButton->setColor(mainwindow->maincurve->annot_marker_color);

  AnnotDurationButton->setColor(mainwindow->maincurve->annot_duration_color);

  AnnotDurationSelectedButton->setColor(mainwindow->maincurve->annot_duration_color_selected);

  if(mainwindow->maincurve->blackwhite_printing)
  {
    checkbox1->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox1->setCheckState(Qt::Unchecked);
  }

  if(mainwindow->clip_to_pane)
  {
    checkbox4->setCheckState(Qt::Checked);
  }
  else
  {
    checkbox4->setCheckState(Qt::Unchecked);
  }

  palette.setColor(QPalette::Text, mainwindow->maincurve->text_color);
  palette.setColor(QPalette::Base, mainwindow->maincurve->backgroundcolor);

  for(i=0; i<mainwindow->files_open; i++)
  {
    if(mainwindow->annotations_dock[i])
    {
      mainwindow->annotations_dock[i]->list->setPalette(palette);
    }
  }

  for(i=0; i<mainwindow->signalcomps; i++)
  {
    mainwindow->signalcomp[i]->color = mainwindow->maincurve->signal_color;
  }

  mainwindow->maincurve->update();
}


void UI_OptionsDialog::loadColorSchema_NK()
{
  mainwindow->maincurve->backgroundcolor.setRed(255);
  mainwindow->maincurve->backgroundcolor.setGreen(255);
  mainwindow->maincurve->backgroundcolor.setBlue(255);

  mainwindow->maincurve->small_ruler_color.setRed(0);
  mainwindow->maincurve->small_ruler_color.setGreen(0);
  mainwindow->maincurve->small_ruler_color.setBlue(0);

  mainwindow->maincurve->big_ruler_color.setRed(255);
  mainwindow->maincurve->big_ruler_color.setGreen(255);
  mainwindow->maincurve->big_ruler_color.setBlue(0);

  mainwindow->maincurve->mouse_rect_color.setRed(0);
  mainwindow->maincurve->mouse_rect_color.setGreen(0);
  mainwindow->maincurve->mouse_rect_color.setBlue(0);

  mainwindow->maincurve->text_color.setRed(0);
  mainwindow->maincurve->text_color.setGreen(0);
  mainwindow->maincurve->text_color.setBlue(0);

  mainwindow->maincurve->baseline_color.setRed(128);
  mainwindow->maincurve->baseline_color.setGreen(128);
  mainwindow->maincurve->baseline_color.setBlue(128);

  mainwindow->maincurve->annot_marker_color.setRed(0);
  mainwindow->maincurve->annot_marker_color.setGreen(0);
  mainwindow->maincurve->annot_marker_color.setBlue(0);

  mainwindow->maincurve->annot_duration_color.setRed(0);
  mainwindow->maincurve->annot_duration_color.setGreen(127);
  mainwindow->maincurve->annot_duration_color.setBlue(127);
  mainwindow->maincurve->annot_duration_color.setAlpha(32);

  mainwindow->maincurve->annot_duration_color_selected.setRed(127);
  mainwindow->maincurve->annot_duration_color_selected.setGreen(0);
  mainwindow->maincurve->annot_duration_color_selected.setBlue(127);
  mainwindow->maincurve->annot_duration_color_selected.setAlpha(32);

  mainwindow->maincurve->signal_color = 2;

  mainwindow->maincurve->floating_ruler_color = 7;

  mainwindow->maincurve->blackwhite_printing = 1;

  mainwindow->show_annot_markers = 1;

  mainwindow->show_baselines = 1;

  mainwindow->maincurve->crosshair_1.color = 7;

  mainwindow->maincurve->crosshair_2.color = 9;

  mainwindow->clip_to_pane = 0;

  update_interface();
}


void UI_OptionsDialog::loadColorSchema_Dark()
{
  mainwindow->maincurve->backgroundcolor.setRed(64);
  mainwindow->maincurve->backgroundcolor.setGreen(64);
  mainwindow->maincurve->backgroundcolor.setBlue(64);

  mainwindow->maincurve->small_ruler_color.setRed(255);
  mainwindow->maincurve->small_ruler_color.setGreen(255);
  mainwindow->maincurve->small_ruler_color.setBlue(255);

  mainwindow->maincurve->big_ruler_color.setRed(128);
  mainwindow->maincurve->big_ruler_color.setGreen(128);
  mainwindow->maincurve->big_ruler_color.setBlue(128);

  mainwindow->maincurve->mouse_rect_color.setRed(255);
  mainwindow->maincurve->mouse_rect_color.setGreen(255);
  mainwindow->maincurve->mouse_rect_color.setBlue(255);

  mainwindow->maincurve->text_color.setRed(255);
  mainwindow->maincurve->text_color.setGreen(255);
  mainwindow->maincurve->text_color.setBlue(255);

  mainwindow->maincurve->baseline_color.setRed(128);
  mainwindow->maincurve->baseline_color.setGreen(128);
  mainwindow->maincurve->baseline_color.setBlue(128);

  mainwindow->maincurve->annot_marker_color.setRed(255);
  mainwindow->maincurve->annot_marker_color.setGreen(255);
  mainwindow->maincurve->annot_marker_color.setBlue(255);

  mainwindow->maincurve->annot_duration_color.setRed(0);
  mainwindow->maincurve->annot_duration_color.setGreen(127);
  mainwindow->maincurve->annot_duration_color.setBlue(127);
  mainwindow->maincurve->annot_duration_color.setAlpha(32);

  mainwindow->maincurve->annot_duration_color_selected.setRed(127);
  mainwindow->maincurve->annot_duration_color_selected.setGreen(0);
  mainwindow->maincurve->annot_duration_color_selected.setBlue(127);
  mainwindow->maincurve->annot_duration_color_selected.setAlpha(32);

  mainwindow->maincurve->signal_color = 12;

  mainwindow->maincurve->floating_ruler_color = 10;

  mainwindow->maincurve->blackwhite_printing = 1;

  mainwindow->show_annot_markers = 1;

  mainwindow->show_baselines = 1;

  mainwindow->maincurve->crosshair_1.color = 7;

  mainwindow->maincurve->crosshair_2.color = 10;

  mainwindow->clip_to_pane = 0;

  update_interface();
}


void UI_OptionsDialog::loadColorSchema_blue_gray()
{
  int i;

  QPalette palette;

  mainwindow->maincurve->backgroundcolor = Qt::gray;
  BgColorButton->setColor(mainwindow->maincurve->backgroundcolor);

  mainwindow->maincurve->small_ruler_color = Qt::black;
  SrColorButton->setColor(mainwindow->maincurve->small_ruler_color);

  mainwindow->maincurve->big_ruler_color = Qt::darkGray;
  BrColorButton->setColor(mainwindow->maincurve->big_ruler_color);

  mainwindow->maincurve->mouse_rect_color = Qt::black;
  MrColorButton->setColor(mainwindow->maincurve->mouse_rect_color);

  mainwindow->maincurve->text_color = Qt::black;
  TxtColorButton->setColor(mainwindow->maincurve->text_color);

  mainwindow->maincurve->signal_color = Qt::blue;
  SigColorButton->setColor(Qt::blue);

  mainwindow->maincurve->baseline_color = Qt::darkGray;
  BaseColorButton->setColor(Qt::darkGray);
  mainwindow->show_baselines = 1;
  checkbox3->setCheckState(Qt::Checked);

  mainwindow->maincurve->crosshair_1.color = Qt::red;
  Crh1ColorButton->setColor(Qt::red);

  mainwindow->maincurve->crosshair_2.color = Qt::cyan;
  Crh2ColorButton->setColor(Qt::cyan);

  mainwindow->maincurve->floating_ruler_color = Qt::red;
  FrColorButton->setColor(Qt::red);

  mainwindow->maincurve->annot_marker_color = Qt::white;
  AnnotMkrButton->setColor(Qt::white);
  mainwindow->show_annot_markers = 1;
  checkbox2->setCheckState(Qt::Checked);

  mainwindow->maincurve->annot_duration_color.setRed(0);
  mainwindow->maincurve->annot_duration_color.setGreen(127);
  mainwindow->maincurve->annot_duration_color.setBlue(127);
  mainwindow->maincurve->annot_duration_color.setAlpha(32);
  AnnotDurationButton->setColor(mainwindow->maincurve->annot_duration_color);

  mainwindow->maincurve->annot_duration_color_selected.setRed(127);
  mainwindow->maincurve->annot_duration_color_selected.setGreen(0);
  mainwindow->maincurve->annot_duration_color_selected.setBlue(127);
  mainwindow->maincurve->annot_duration_color_selected.setAlpha(32);

  palette.setColor(QPalette::Text, mainwindow->maincurve->text_color);
  palette.setColor(QPalette::Base, mainwindow->maincurve->backgroundcolor);

  for(i=0; i<mainwindow->files_open; i++)
  {
    if(mainwindow->annotations_dock[i])
    {
      mainwindow->annotations_dock[i]->list->setPalette(palette);
    }
  }

  for(i=0; i<mainwindow->signalcomps; i++)
  {
    mainwindow->signalcomp[i]->color = mainwindow->maincurve->signal_color;
  }

  mainwindow->maincurve->blackwhite_printing = 1;

  checkbox1->setCheckState(Qt::Checked);

  checkbox4->setCheckState(Qt::Unchecked);

  mainwindow->maincurve->update();
}


void UI_OptionsDialog::lineedit4_1_changed(const QString qstr)
{
  int i, j, len, cp;

  char str[32];

  strlcpy(str, qstr.toLatin1().data(), 32);
  trim_spaces(str);
  len = strlen(str);

  cp = lineedit4_1->cursorPosition();

  for(i=0; i<len; i++)
  {
    if((str[i] < 32) || (str[i] > 126))
    {
      for(j=i; j<len; j++)
      {
        str[j] = str[j+1];
      }

      i--;
    }
  }

  lineedit4_1->setText(str);

  lineedit4_1->setCursorPosition(cp);

  if(strlen(mainwindow->ecg_qrs_rpeak_descr))
  {
    strlcpy(mainwindow->ecg_qrs_rpeak_descr, str, 32);
  }
  else
  {
    strlcpy(mainwindow->ecg_qrs_rpeak_descr, "R-wave", 32);
  }
}


void UI_OptionsDialog::ApplyButton5Clicked()
{
  mainwindow->font_size = spinbox5_1->value();
  mainwindow->monofont_size = spinbox5_2->value();

  QMessageBox::information(optionsdialog, "Font size changed", "You need to restart the application for the changes to take effect.");

  ApplyButton5->setEnabled(false);
}


void UI_OptionsDialog::spinBox5_1ValueChanged(int val)
{
  QFont myfont = *mainwindow->myfont;
  myfont.setPointSize(val);
  textEdit5_1->setFont(myfont);
  textEdit5_1->setPlainText("The quick brown fox jumps over the lazy dog. 0123456789 AaBbYyZz");

  ApplyButton5->setEnabled(true);
}


void UI_OptionsDialog::spinBox5_2ValueChanged(int val)
{
  QFont monofont = *mainwindow->monofont;
  monofont.setPointSize(val);
  textEdit5_2->setFont(monofont);
  textEdit5_2->setPlainText("The quick brown fox jumps over the lazy dog. 0123456789 AaBbYyZz");

  ApplyButton5->setEnabled(true);
}


void UI_OptionsDialog::DefaultButton5Clicked()
{
  spinbox5_1->setValue(mainwindow->sys_font_size);

  spinbox5_2->setValue(mainwindow->sys_monofont_size);
}











