// Copyright (c) 2019 The OASIS developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ADDRESSLABELROW_H
#define ADDRESSLABELROW_H

#include <QWidget>

namespace Ui {
class AddressLabelRow;
}

class AddressLabelRow : public QWidget
{
    Q_OBJECT

public:
    explicit AddressLabelRow(QWidget *parent = nullptr);
    ~AddressLabelRow();

    void init(bool isLightTheme, bool isHover);

    void updateState(bool isLightTheme, bool isHovered, bool isSelected);
    void updateView(const QString& address, const QString& label);
protected:
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);

private:
    Ui::AddressLabelRow *ui;
};

#endif // ADDRESSLABELROW_H
