// Copyright (c) 2019 The OASIS developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "qt/oasis/myaddressrow.h"
#include "qt/oasis/forms/ui_myaddressrow.h"

MyAddressRow::MyAddressRow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyAddressRow)
{
    ui->setupUi(this);
    ui->labelName->setProperty("cssClass", "text-list-title1");
    ui->labelAddress->setProperty("cssClass", "text-list-body2");
    ui->labelDate->setProperty("cssClass", "text-list-caption");
}

void MyAddressRow::updateView(const QString& address, const QString& label, const QString& date){
    ui->labelName->setText(label);
    ui->labelAddress->setText(address);
    if (date.isEmpty()){
        ui->labelDate->setVisible(false);
    } else {
        ui->labelDate->setVisible(true);
        ui->labelDate->setText(date);
    }
}

MyAddressRow::~MyAddressRow(){
    delete ui;
}
