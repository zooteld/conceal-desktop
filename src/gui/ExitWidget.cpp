// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2018 The Circle Foundation & Conceal Devs
// Copyright (c) 2018-2020 Conceal Network & Conceal Devs
//
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ExitWidget.h"

#include <QIcon>
#include <QMovie>

#include "CurrencyAdapter.h"
#include "ui_exitwidget.h"

namespace WalletGui {

ExitWidget::ExitWidget(QWidget* _parent)
    : QWidget(_parent, Qt::Window), m_ui(new Ui::ExitWidget), m_clockMovie(new QMovie(this))
{
  m_ui->setupUi(this);
  setWindowIcon(QIcon(":/images/w2w-logo"));
  QString text = m_ui->m_label->text();
  m_ui->m_label->setText(text.arg(CurrencyAdapter::instance().getCurrencyDisplayName()));
  m_clockMovie->setFileName(":/images/clock");
  m_clockMovie->setScaledSize(QSize(48, 48));
  m_ui->m_clockLabel->setMovie(m_clockMovie);
  m_clockMovie->start();
}

ExitWidget::~ExitWidget()
{
}

}  // namespace WalletGui
