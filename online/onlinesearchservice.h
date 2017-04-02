/*
 * Cantata
 *
 * Copyright (c) 2011-2017 Craig Drummond <craig.p.drummond@gmail.com>
 *
 * ----
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef ONLINESEARCH_SERVICE_H
#define ONLINESEARCH_SERVICE_H

#include "onlineservice.h"
#include "models/searchmodel.h"

class NetworkJob;

class OnlineSearchService : public SearchModel, public OnlineService
{
public:
    OnlineSearchService(QObject *p);
    virtual ~OnlineSearchService() { cancel(); }

    QVariant data(const QModelIndex &index, int role) const;
    Song & fixPath(Song &s) const;
    virtual void search(const QString &key, const QString &value) =0;
    virtual void cancel();

protected:
    NetworkJob *job;
};

#endif
