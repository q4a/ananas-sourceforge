/****************************************************************************
** $Id: main.cpp,v 1.2 2005/12/19 12:42:12 gr Exp $
** 
** Tool for automatic running Ananas tests
**
** Created : 20051024
**
** Copyright (C) 2003-2005. Grigory Panov <gr1313 at mail.ru>, Yoshkar-Ola
**
** This file is part of the Designer application of the Ananas
** automation accounting system.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.leaderit.ru/page=ananas or email sales@leaderit.ru
** See http://www.leaderit.ru/gpl/ for GPL licensing information.
**
** Contact org@leaderit.ru if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/


//#define STOP_ON_ERROR "stop on error

//#define BIG_CATALOGUE "catalogue1"
//#define BIG_DOCUMENT "document1"

#include "ananas.h"
#include <qapplication.h>
#include <math.h>
#include <qmap.h>


double rnd(double m=1);


double rnd(double m)
{
	double res;
#ifdef _Windows
	res = rand()*m;
#else
	res = random()*m;
#endif
	return res;
	
}
double summ(int l, int r)
{
	double res =0;
	for(uint i=l; i<=r;i++)
	{
		res+=i;
	}
	return res;
}


void createConfiguration(	const QMap<QString,QString> &mapGlobal, 
				const QMap<QString, QString> &mapLocal,
				const QString &log)
{
//	printf("create config\n");
	
	aCfg c;
	aCfgItem d1, c1, c2, doc, ar, t;
	
	const QString test_name = "test saldo1";
	const QString DB_TITLE = "Test 2";
	const QString DB_TYPE = mapGlobal["db_type"];
	const QString DB_PORT = mapGlobal["db_port"];
	const QString DB_USER = mapGlobal["db_user"];
	const QString DB_PASS = mapGlobal["db_password"];
	const QString DB_HOST = mapGlobal["db_host"];
	
	const QString DB_NAME = mapLocal["db_name"];
	const QString DB_CONFIGFILE = mapLocal["db_config"];
	const QString DB_RC = mapLocal["db_rc"];
	
	c.createNew();
	c.setInfo( md_info_name, "????????" );
	c.setInfo( md_info_author, "anonimus" );

	c1 = c.insertCatalogue( "????????????" );
	
	c.insertField( c1, md_group, "????????????????????????", "C 100" );
	c.insertField( c1, md_element, "????????????????????????", "C 100" );
	
	c2 = c.insertCatalogue( "??????????????????????" );

	c.insertField( c2, md_group, "????????????????????????", "C 100" );
	c.insertField( c2, md_element, "????????????????????????", "C 100" );
	
	doc = c.insertDocument("???????????????? ????????????????");

	c.insertField( doc, md_header, "??????????", "C 40" );
	c.insertField( doc, md_header, "????????", "D" );
	c.insertField( doc, md_header, "??????????????????", "C 100" );
	c.insertField( doc, md_header, "????????????????????", QString("O %1").arg(c.attr(c2,mda_id)) );
	
	t = c.insertDocumentTable(doc,"??????????????");
	
	c.insertField( t, "", "????????????????????????", QString("O %1").arg(c.attr(c1,mda_id)) );
	c.insertField( t, "", "????????????????????", "N 5 0" );
	c.insertField( t, "", "????????", "N 10 2" );
	c.insertField( t, "", "??????????", "N 12 2" );
	
	ar = c.insertARegister( "?????????????? ??????????" );
	c.insertField( ar, md_dimensions, "??????????", "C 10" );
	c.insertField( ar, md_dimensions, "????????????", "C 10" );
	c.insertField( ar, md_dimensions, "??????????", QString("O %1").arg(c.attr(c1,mda_id)) );
	c.insertField( ar, md_dimensions, "????????????????????", QString("O %1").arg(c.attr(c2,mda_id)) );
	c.insertField( ar, md_resources, "????????????????????", "N 10" );
	c.insertField( ar, md_resources, "??????????", "N 12 2" );
	
	// Set resource values
	c.rc.setValue("dbtitle", DB_TITLE);
	c.rc.setValue("dbtype", DB_TYPE);
	c.rc.setValue("dbname", DB_NAME);
	c.rc.setValue("dbuser", DB_USER);
	c.rc.setValue("dbpass", DB_PASS);
	c.rc.setValue("dbhost", DB_HOST);
	c.rc.setValue("dbport", DB_PORT);
	c.rc.setValue("configfile", DB_CONFIGFILE);
	
	if(!c.writerc( DB_RC ))
	{
		aTests::print2log(log,test_name,"OK",QString("write configuration"));
	}
	else
	{
		aTests::print2log(log,test_name,"ERROR",QString("write configuration"));
	}
	//return true;
}

void delete_cat(aCatalogue *cat)
{
	cat->Select();
	bool res = false;
	while(!res)
	{
		res = cat->selectByLevel(0);
		cat->GroupDelete();
	}
}

bool create_cat(aCatalogue *cat,int count)
{
	bool res =0;
	cat->UnSelect();
	res+=cat->GroupNew();
	res+=cat->GroupSetValue("????????????????????????","???????????????? ????????????");
	res+=cat->Update();
	for(uint i=0; i<count; i++)
	{
		res+=cat->New(false);
		res+=cat->SetValue("????????????????????????", QString("????????????????????????%1").arg(i));
		res+=cat->Update();
	}
return 0;
}

int main(int argc, char **argv)
{
	QApplication appication(argc,argv,false);	
	aDatabase db;
	QString log, globalConfig, localConfig;
	const QString test_name = "test saldo1";
	log = 		aTests::parseCommandLine(argc,argv,"--log");
	globalConfig = 	aTests::parseCommandLine(argc,argv,"--globalconfig");
	localConfig = 	aTests::parseCommandLine(argc,argv,"--localconfig");
	
	QMap<QString,QString> mapGlobal = aTests::readConfig(globalConfig,log);
	QMap<QString,QString> mapLocal = aTests::readConfig(localConfig,log);
	
	createConfiguration(mapGlobal,mapLocal,log);

	if(db.init(mapLocal["db_rc"]))
	{
		aTests::print2log(log,test_name,"OK",QString("database init"));
		if(db.update())
		{
			aTests::print2log(log,test_name,"OK",QString("database update"));
		}
		else
		{
			aTests::print2log(log,test_name,"ERROR",QString("database update"));
			return 1;
		}
	}
	else
	{
		aTests::print2log(log,test_name,"ERROR",QString("database init"));	
		return 1;
	}
	
	int count_doc =10;
	int count_table_line=10;
	
	if(mapLocal.find("document count")!=mapLocal.end())
	{
		count_doc = mapLocal["document count"].toInt();
	}
	else
	{
		aTests::print2log(log,test_name,"WARNING",QString("can't find parametr `document count'"));
	}
	if(mapLocal.find("document table count")!=mapLocal.end())
	{
		count_table_line = mapLocal["document table count"].toInt();
	}
	else
	{
		aTests::print2log(log,test_name,"WARNING",QString("can't find parametr `document table count'"));
	}
	int i=0;
	int j;
	aCatalogue* cat1 = new aCatalogue("??????????????????????",&db);
	if(cat1)
	{
		aTests::print2log(log,test_name,"OK",QString("catalogue1 create"));
	}
	else
	{
		aTests::print2log(log,test_name,"ERROR",QString("catalog1 create"));
		return 1;
	}
	aCatalogue* cat2 = new aCatalogue("????????????",&db);
	if(cat2)
	{
		aTests::print2log(log,test_name,"OK",QString("catalogue2 create"));
	}
	else
	{
		aTests::print2log(log,test_name,"ERROR",QString("catalog2 create"));
		return 1;
	}
	
	delete_cat(cat1);
	delete_cat(cat2);
	if(create_cat(cat1,count_doc)==0)
	{
		aTests::print2log(log,test_name,"OK",QString("catalogue1 fill"));
	}
	else
	{
		aTests::print2log(log,test_name,"WARNING",QString("catalog1 fill"));
	}
			
	if(create_cat(cat2,count_table_line)==0)
	{
		aTests::print2log(log,test_name,"OK",QString("catalogue2 fill"));
	}
	else
	{
		aTests::print2log(log,test_name,"WARNING",QString("catalog2 fill"));
	}
	
	cat1->Select();
	
	if(cat1->First())
	{
		 aTests::print2log(log,test_name,"OK",QString("catalogue1 select"));
	}
	else
	{
		 aTests::print2log(log,test_name,"ERROR",QString("catalogue1 select"));
		 return 1;
	}
	cat2->Select();
	
	aDocument *doc = new aDocument("???????????????? ????????????????",&db);
	if(doc)
	{
		aTests::print2log(log,test_name,"OK",QString("test document created"));
	}
	else
	{
		aTests::print2log(log,test_name,"ERROR",QString("test document created"));
		return 1;
	}

	aARegister *ar = new aARegister("?????????????? ??????????",&db);
	if(ar)
	{
		aTests::print2log(log,test_name,"OK",QString("aAregister created"));
	}
	else
	{
		aTests::print2log(log,test_name,"ERROR",QString("aAregister created"));
		return 1;
	
	}
	ar->SetDocument(doc); 
	ar->SetTable("??????????????");
	
	for ( i=0; i<count_doc;i++)
	{
		doc->New();
		doc->SetValue("??????????",i);
		doc->SetValue("????????", QDateTime::currentDateTime());
		doc->SetValue("??????????????????", QString("???????????????? ?????????????????? #%1").arg(i));
		doc->SetValue("????????????????????", cat1->sysValue("id"));
		doc->Update();
		cat2->First();
		for(j=0; j<count_table_line; j++)
		{
			doc->TableSelect("??????????????");
			doc->TableNewLine("??????????????");
			doc->TableSetValue("??????????????","????????????????????????",cat2->sysValue("id"));
			doc->TableSetValue("??????????????","????????????????????",j+1);
			doc->TableSetValue("??????????????","????????",1);
			doc->TableSetValue("??????????????","??????????",j+1);
			doc->TableUpdate("??????????????");
			ar->New();
			ar->SetValue("??????????","41.2"); 
			ar->SetValue("????????????","60");
			ar->SetValue("????????????????????",j+1);
			ar->SetValue("??????????",j+1);
			ar->SetValue("??????????",cat2->sysValue("id"));
			ar->SetValue("????????????????????",cat1->sysValue("id"));
			ar->Update();
			cat2->Next();
		}
		cat1->Next(); 
		if(doc->Conduct()==0)
		{
			aTests::print2log(log,test_name,"OK",QString("document conducted"));
		}
		else
		{
			aTests::print2log(log,test_name,"ERROR",QString("document conducted"));
			return 1;
		}
		
	}
	cat1->First();
	for ( i=0; i<count_table_line;i++)
	{
		
		QVariant summa= ar->getSaldo(QDateTime::currentDateTime(),"????????????????????",cat1->sysValue("id"),"??????????");
		if(summa==summ(0,count_table_line))
		{
			aTests::print2log(log,test_name,"OK",QString("saldo kontragent %1=%2").arg(summa.toString()).arg(summ(0,count_table_line)));
		}
		else
		{
			aTests::print2log(log,test_name,"ERROR",QString("saldo kontragent %1!=%2").arg(summa.toString()).arg(summ(0,count_table_line)));
		}
		cat1->Next();
	}
	cat2->First();
	for ( i=0; i<count_table_line;i++)
	{
		
		QVariant summa= ar->getSaldo(QDateTime::currentDateTime(),"??????????",cat2->sysValue("id"),"????????????????????");
		if(summa==(i+1)*count_doc)
		{
			aTests::print2log(log,test_name,"OK",QString("saldo tovar%1=%2").arg(summa.toString()).arg((i+1)*count_doc));
		}
		else
		{
			aTests::print2log(log,test_name,"ERROR",QString("saldo tovar%1!=%2").arg(summa.toString()).arg((i+1)*count_doc));
		}
		cat2->Next();
	}
	delete cat1;
	delete cat2;
	delete doc;
	delete ar;
	return 0;
}
