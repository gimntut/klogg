/*
 * Copyright (C) 2009, 2010 Nicolas Bonnefon and other contributors
 *
 * This file is part of glogg.
 *
 * glogg is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * glogg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with glogg.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Copyright (C) 2016 -- 2019 Anton Filimonov and other contributors
 *
 * This file is part of klogg.
 *
 * klogg is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * klogg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with klogg.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INFOLINE_H
#define INFOLINE_H

#include <QLabel>
#include <QPalette>
#include <absl/types/optional.h>

// Information line with integrated completion gauge
// used for the file name and the search results.
class InfoLine : public QLabel {
    Q_OBJECT
  public:
    InfoLine();

    // Display the gauge in the background with the passed value (0-100)
    // This function doesn't change the text of the widget.
    void displayGauge( int completion );
    // Hide the gauge and make the widget like a normal QLabel
    void hideGauge();

  protected:
    void paintEvent( QPaintEvent* paintEvent ) override;
    void contextMenuEvent( QContextMenuEvent* event ) override;

  private:
    // The original palette of the QLabel
    absl::optional<QPalette> origPalette_;
};

#endif
