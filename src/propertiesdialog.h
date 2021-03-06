/***************************************************************************
 *   Copyright (C) 2010 by Petr Vanek                                      *
 *   petr@scribus.info                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#ifndef PROPERTIESDIALOG_H
#define PROPERTIESDIALOG_H

#include "ui_propertiesdialog.h"

class PropertiesDialog : public QDialog, Ui::PropertiesDialog
{
    Q_OBJECT

    QString oldAccelText; // Placeholder when editing shortcut

    public:
        PropertiesDialog(QWidget *parent=NULL);
        ~PropertiesDialog();

    signals:
        void propertiesChanged();

    private:
        void setFontSample(const QFont & f);
        void openBookmarksFile(const QString &fname);
        void saveBookmarksFile(const QString &fname);

    private slots:
        void apply();
        void accept();
        
        void changeFontButton_clicked();
        void chooseBackgroundImageButton_clicked();
        void bookmarksButton_clicked();

    protected:
        void setupShortcuts();
        void saveShortcuts();
        void recordAction(int row, int column);
        void validateAction(int row, int column);
};


#endif

