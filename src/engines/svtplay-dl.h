/*
 *
 *  Copyright (c) 2022
 *  name : Francis Banyikwa
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QByteArray>

#include "../engines.h"

class settings ;

class svtplay_dl : public engines::engine::functions
{
public:
	static const char * testData() ;

	~svtplay_dl() override ;
	svtplay_dl( const engines&,const engines::engine&,QJsonObject& ) ;

	class svtplay_dlFilter : public engines::engine::functions::filter
	{
	public:
		svtplay_dlFilter( settings&,const engines::engine&,int ) ;

		const QByteArray& operator()( const Logger::Data& e ) override ;

		~svtplay_dlFilter() override ;
	private:
		QByteArray m_tmp ;
		QByteArray m_fileName ;
		engines::engine::functions::preProcessing m_preProcessing ;
	} ;

	engines::engine::functions::FilterOutPut filterOutput() override ;

	void updateOutPutChannel( QProcess::ProcessChannel& ) const override ;

	void updateDownLoadCmdOptions( const engines::engine::functions::updateOpts& ) override ;

	QStringList horizontalHeaderLabels() const override ;

	std::vector< engines::engine::functions::mediaInfo > mediaProperties( const QByteArray& ) override ;

	const QProcessEnvironment& processEnvironment() const override ;

	engines::engine::functions::DataFilter Filter( int ) override ;

	QString updateTextOnCompleteDownlod( const QString& uiText,
					     const QString& bkText,
					     const QString& downloadingOptions,
					     const engines::engine::functions::finishedState& ) override ;
private:
	QProcessEnvironment m_processEnvironment ;
};
