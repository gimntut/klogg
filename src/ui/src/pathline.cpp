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

#include "pathline.h"

#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QContextMenuEvent>
#include <QMenu>

#include "openfilehelper.h"

void PathLine::setPath( const QString& path )
{
    path_ = path;
}

void PathLine::contextMenuEvent( QContextMenuEvent* event )
{
    QMenu menu( this );

    auto copyPath = menu.addAction( "Copy full path" );
    auto openContainingFolder = menu.addAction( "Open containing folder" );
    menu.addSeparator();
    auto copySelection = menu.addAction( "Copy" );
    menu.addSeparator();
    auto selectAll = menu.addAction( "Select all" );

    connect( copyPath, &QAction::triggered,
             [this]( auto ) { QApplication::clipboard()->setText( this->path_ ); } );

    connect( openContainingFolder, &QAction::triggered,
             [this]( auto ) { showPathInFileExplorer( this->path_ ); } );

    copySelection->setEnabled( this->hasSelectedText() );
    connect( copySelection, &QAction::triggered,
             [this]( auto ) { QApplication::clipboard()->setText( this->selectedText() ); } );

    connect( selectAll, &QAction::triggered,
             [this]( auto ) { setSelection( 0, this->text().length() ); } );

    menu.exec( event->globalPos() );
}
