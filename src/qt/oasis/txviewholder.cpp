// Copyright (c) 2019 The OASIS developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "qt/oasis/txviewholder.h"
#include "qt/oasis/qtutils.h"
#include "transactiontablemodel.h"
#include <QModelIndex>

#define ADDRESS_SIZE 12

QWidget* TxViewHolder::createHolder(int pos)
{
    if (!txRow) txRow = new TxRow();
    txRow->init(isLightTheme);
    return txRow;
}

void TxViewHolder::init(QWidget* holder, const QModelIndex &index, bool isHovered, bool isSelected) const
{
    QModelIndex rIndex = (filter) ? filter->mapToSource(index) : index;
    int type = rIndex.data(TransactionTableModel::TypeRole).toInt();

    TxRow *txRow = static_cast<TxRow*>(holder);
    txRow->updateStatus(isLightTheme, isHovered, isSelected);

    QDateTime date = rIndex.data(TransactionTableModel::DateRole).toDateTime();
    QModelIndex indexType = rIndex.sibling(rIndex.row(),TransactionTableModel::Type);
    QString label = indexType.data(Qt::DisplayRole).toString();

    bool hasDoubleAmount = type == TransactionRecord::SendToSelfShieldedAddress || type == TransactionRecord::SendToSelfShieldToTransparent;
    txRow->showHideSecondAmount(hasDoubleAmount);

        QString address = rIndex.data(Qt::DisplayRole).toString();
        if (!address.isEmpty()) {
            if (type == TransactionRecord::SendToNobody) {
                // OP_RETURN record with a valid utf-8 string to show
                label.clear();
                label += address;
            } else {
                // Regular addresses
                if (address.length() > 20) {
                    address = address.left(ADDRESS_SIZE) + "..." + address.right(ADDRESS_SIZE);
                }
                label += " " + address;
            }
        }

    qint64 amountTop = rIndex.data(TransactionTableModel::AmountRole).toLongLong();
    int status = rIndex.data(TransactionTableModel::StatusRole).toInt();
    bool isUnconfirmed = (status == TransactionStatus::Unconfirmed) || (status == TransactionStatus::Immature)
                         || (status == TransactionStatus::Conflicted) || (status == TransactionStatus::NotAccepted);

    txRow->setDate(date);
    txRow->setLabel(label);
    QString amountText = BitcoinUnits::formatWithUnit(nDisplayUnit, amountTop, true, BitcoinUnits::separatorAlways);
    if (hasDoubleAmount) {
        qint64 amountBottom = rIndex.data(TransactionTableModel::ShieldedCreditAmountRole).toLongLong();
        QString amountBottomText = BitcoinUnits::formatWithUnit(nDisplayUnit, amountBottom, true, BitcoinUnits::separatorAlways);
        txRow->setAmount(amountBottomText + (type == TransactionRecord::SendToSelfShieldedAddress ? " shielded" : ""),
                         amountText + " fee");
    } else {
        txRow->setAmount(amountText, "");
    }
    txRow->setType(isLightTheme, type, !isUnconfirmed);
}

QColor TxViewHolder::rectColor(bool isHovered, bool isSelected)
{
    return getRowColor(isLightTheme, isHovered, isSelected);
}
