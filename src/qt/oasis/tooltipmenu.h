// Copyright (c) 2019 The OASIS developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TOOLTIPMENU_H
#define TOOLTIPMENU_H

#include "qt/oasis/pwidget.h"
#include <QWidget>
#include <QModelIndex>

class OASISGUI;
class WalletModel;

namespace Ui {
class TooltipMenu;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class TooltipMenu : public PWidget
{
    Q_OBJECT

public:
    explicit TooltipMenu(OASISGUI* _window, QWidget *parent = nullptr);
    ~TooltipMenu() override;

    virtual void showEvent(QShowEvent *event) override;

    void setEditBtnText(const QString& btnText);
    void setDeleteBtnText(const QString& btnText);
    void setCopyBtnText(const QString& btnText);
    void setLastBtnText(const QString& btnText, int minHeight = 30);
    void setCopyBtnVisible(bool visible);
    void setDeleteBtnVisible(bool visible);
    void setEditBtnVisible(bool visible);
    void setLastBtnVisible(bool visible);
    void setLastBtnCheckable(bool checkable, bool isChecked);

Q_SIGNALS:
    void onDeleteClicked();
    void onCopyClicked();
    void onEditClicked();
    void onLastClicked();

private Q_SLOTS:
    void deleteClicked();
    void copyClicked();
    void editClicked();
    void lastClicked();

private:
    Ui::TooltipMenu *ui;
    QModelIndex index;
};

#endif // TOOLTIPMENU_H
