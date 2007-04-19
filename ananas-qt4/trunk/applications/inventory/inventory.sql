-- MySQL dump 10.10
--
-- Host: localhost    Database: ananas_inventory
-- ------------------------------------------------------
-- Server version	5.0.18

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `a_journ`
--

CREATE TABLE `a_journ` (
  `id` bigint(20) NOT NULL,
  `typej` int(11) default NULL,
  `idd` bigint(20) default NULL,
  `typed` int(11) default NULL,
  `ddate` datetime default NULL,
  `pnum` char(254) NOT NULL,
  `num` int(11) default NULL,
  `mf` char(1) default NULL,
  `df` char(1) default NULL,
  `cf` char(1) default NULL,
  PRIMARY KEY  (`id`),
  KEY `a_journ_idx0` (`typej`),
  KEY `a_journ_idx1` (`idd`),
  KEY `a_journ_idx2` (`typed`),
  KEY `a_journ_idx3` (`ddate`),
  KEY `a_journ_idx4` (`pnum`),
  KEY `a_journ_idx5` (`num`),
  KEY `a_journ_idx6` (`mf`),
  KEY `a_journ_idx7` (`df`),
  KEY `a_journ_idx8` (`cf`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `a_journ`
--


/*!40000 ALTER TABLE `a_journ` DISABLE KEYS */;
LOCK TABLES `a_journ` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `a_journ` ENABLE KEYS */;

--
-- Table structure for table `ce129`
--

CREATE TABLE `ce129` (
  `id` bigint(20) NOT NULL,
  `df` char(1) default NULL,
  `idg` bigint(20) default NULL,
  `ido` bigint(20) default NULL,
  `uf134` char(120) default NULL,
  `uf138` char(30) default NULL,
  `uf136` char(120) default NULL,
  `uf642` decimal(3,1) default NULL,
  `uf644` decimal(3,1) default NULL,
  `uf819` char(254) default NULL,
  `uf1146` char(30) default NULL,
  PRIMARY KEY  (`id`),
  KEY `ce129_idx0` (`df`),
  KEY `ce129_idx1` (`idg`),
  KEY `ce129_idx2` (`ido`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ce129`
--


/*!40000 ALTER TABLE `ce129` DISABLE KEYS */;
LOCK TABLES `ce129` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `ce129` ENABLE KEYS */;

--
-- Table structure for table `ce310`
--

CREATE TABLE `ce310` (
  `id` bigint(20) NOT NULL,
  `df` char(1) default NULL,
  `idg` bigint(20) default NULL,
  `ido` bigint(20) default NULL,
  `uf315` char(60) default NULL,
  `uf317` char(160) default NULL,
  `uf776` char(100) default NULL,
  `uf778` char(200) default NULL,
  `uf780` char(100) default NULL,
  `uf782` char(6) default NULL,
  `uf784` char(30) default NULL,
  `uf786` char(30) default NULL,
  `uf788` char(254) default NULL,
  `uf790` char(100) default NULL,
  `uf792` char(100) default NULL,
  `uf794` char(100) default NULL,
  `uf796` char(100) default NULL,
  `uf798` char(254) default NULL,
  PRIMARY KEY  (`id`),
  KEY `ce310_idx0` (`df`),
  KEY `ce310_idx1` (`idg`),
  KEY `ce310_idx2` (`ido`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ce310`
--


/*!40000 ALTER TABLE `ce310` DISABLE KEYS */;
LOCK TABLES `ce310` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `ce310` ENABLE KEYS */;

--
-- Table structure for table `ce828`
--

CREATE TABLE `ce828` (
  `id` bigint(20) NOT NULL,
  `df` char(1) default NULL,
  `idg` bigint(20) default NULL,
  `ido` bigint(20) default NULL,
  `uf838` char(200) default NULL,
  `uf840` char(200) default NULL,
  PRIMARY KEY  (`id`),
  KEY `ce828_idx0` (`df`),
  KEY `ce828_idx1` (`idg`),
  KEY `ce828_idx2` (`ido`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ce828`
--


/*!40000 ALTER TABLE `ce828` DISABLE KEYS */;
LOCK TABLES `ce828` WRITE;
INSERT INTO `ce828` VALUES (1,'0',0,NULL,'ИНН',''),(2,'0',0,NULL,'Расч. счет',''),(3,'0',0,NULL,'Название',''),(4,'0',0,NULL,'Руководитель',''),(5,'0',0,NULL,'Главный бухгалтер',''),(6,'0',0,NULL,'КПП',''),(7,'0',0,NULL,'Банк',''),(8,'0',0,NULL,'Кассир',''),(9,'0',0,NULL,'ОКУД',''),(10,'0',0,NULL,'ОКПО',''),(11,'0',0,NULL,'Адрес','');
UNLOCK TABLES;
/*!40000 ALTER TABLE `ce828` ENABLE KEYS */;

--
-- Table structure for table `ce909`
--

CREATE TABLE `ce909` (
  `id` bigint(20) NOT NULL,
  `df` char(1) default NULL,
  `idg` bigint(20) default NULL,
  `ido` bigint(20) default NULL,
  `uf917` char(100) default NULL,
  `uf921` decimal(3,0) default NULL,
  PRIMARY KEY  (`id`),
  KEY `ce909_idx0` (`df`),
  KEY `ce909_idx1` (`idg`),
  KEY `ce909_idx2` (`ido`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ce909`
--


/*!40000 ALTER TABLE `ce909` DISABLE KEYS */;
LOCK TABLES `ce909` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `ce909` ENABLE KEYS */;

--
-- Table structure for table `cg129`
--

CREATE TABLE `cg129` (
  `id` bigint(20) NOT NULL,
  `df` char(1) default NULL,
  `level` bigint(20) default NULL,
  `idp` bigint(20) default NULL,
  `uf146` char(80) default NULL,
  PRIMARY KEY  (`id`),
  KEY `cg129_idx0` (`df`),
  KEY `cg129_idx1` (`level`),
  KEY `cg129_idx2` (`idp`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `cg129`
--


/*!40000 ALTER TABLE `cg129` DISABLE KEYS */;
LOCK TABLES `cg129` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `cg129` ENABLE KEYS */;

--
-- Table structure for table `cg310`
--

CREATE TABLE `cg310` (
  `id` bigint(20) NOT NULL,
  `df` char(1) default NULL,
  `level` bigint(20) default NULL,
  `idp` bigint(20) default NULL,
  `uf638` char(150) default NULL,
  PRIMARY KEY  (`id`),
  KEY `cg310_idx0` (`df`),
  KEY `cg310_idx1` (`level`),
  KEY `cg310_idx2` (`idp`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `cg310`
--


/*!40000 ALTER TABLE `cg310` DISABLE KEYS */;
LOCK TABLES `cg310` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `cg310` ENABLE KEYS */;

--
-- Table structure for table `cg828`
--

CREATE TABLE `cg828` (
  `id` bigint(20) NOT NULL,
  `df` char(1) default NULL,
  `level` bigint(20) default NULL,
  `idp` bigint(20) default NULL,
  `uf836` char(50) default NULL,
  PRIMARY KEY  (`id`),
  KEY `cg828_idx0` (`df`),
  KEY `cg828_idx1` (`level`),
  KEY `cg828_idx2` (`idp`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `cg828`
--


/*!40000 ALTER TABLE `cg828` DISABLE KEYS */;
LOCK TABLES `cg828` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `cg828` ENABLE KEYS */;

--
-- Table structure for table `cg909`
--

CREATE TABLE `cg909` (
  `id` bigint(20) NOT NULL,
  `df` char(1) default NULL,
  `level` bigint(20) default NULL,
  `idp` bigint(20) default NULL,
  `uf919` char(100) default NULL,
  PRIMARY KEY  (`id`),
  KEY `cg909_idx0` (`df`),
  KEY `cg909_idx1` (`level`),
  KEY `cg909_idx2` (`idp`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `cg909`
--


/*!40000 ALTER TABLE `cg909` DISABLE KEYS */;
LOCK TABLES `cg909` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `cg909` ENABLE KEYS */;

--
-- Table structure for table `dh1002`
--

CREATE TABLE `dh1002` (
  `id` bigint(20) NOT NULL,
  `uf1221` char(50) default NULL,
  `uf1223` datetime default NULL,
  `uf1225` bigint(20) default NULL,
  `uf1227` char(200) default NULL,
  `uf1229` decimal(14,2) default NULL,
  `uf1231` char(200) default NULL,
  `uf1233` char(254) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `dh1002`
--


/*!40000 ALTER TABLE `dh1002` DISABLE KEYS */;
LOCK TABLES `dh1002` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `dh1002` ENABLE KEYS */;

--
-- Table structure for table `dh101`
--

CREATE TABLE `dh101` (
  `id` bigint(20) NOT NULL,
  `uf121` char(100) default NULL,
  `uf123` datetime default NULL,
  `uf354` char(254) default NULL,
  `uf629` bigint(20) default NULL,
  `uf986` bigint(20) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `dh101`
--


/*!40000 ALTER TABLE `dh101` DISABLE KEYS */;
LOCK TABLES `dh101` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `dh101` ENABLE KEYS */;

--
-- Table structure for table `dh1051`
--

CREATE TABLE `dh1051` (
  `id` bigint(20) NOT NULL,
  `uf1124` decimal(10,0) default NULL,
  `uf1126` datetime default NULL,
  `uf1318` bigint(20) default NULL,
  `uf1320` decimal(12,2) default NULL,
  `uf1322` char(254) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `dh1051`
--


/*!40000 ALTER TABLE `dh1051` DISABLE KEYS */;
LOCK TABLES `dh1051` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `dh1051` ENABLE KEYS */;

--
-- Table structure for table `dh1061`
--

CREATE TABLE `dh1061` (
  `id` bigint(20) NOT NULL,
  `uf1129` char(100) default NULL,
  `uf1131` datetime default NULL,
  `uf1148` bigint(20) default NULL,
  `uf1150` decimal(14,2) default NULL,
  `uf1152` char(254) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `dh1061`
--


/*!40000 ALTER TABLE `dh1061` DISABLE KEYS */;
LOCK TABLES `dh1061` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `dh1061` ENABLE KEYS */;

--
-- Table structure for table `dh576`
--

CREATE TABLE `dh576` (
  `id` bigint(20) NOT NULL,
  `uf582` char(100) default NULL,
  `uf584` datetime default NULL,
  `uf586` bigint(20) default NULL,
  `uf766` char(254) default NULL,
  `uf984` bigint(20) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `dh576`
--


/*!40000 ALTER TABLE `dh576` DISABLE KEYS */;
LOCK TABLES `dh576` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `dh576` ENABLE KEYS */;

--
-- Table structure for table `dh874`
--

CREATE TABLE `dh874` (
  `id` bigint(20) NOT NULL,
  `uf880` char(100) default NULL,
  `uf882` datetime default NULL,
  `uf884` bigint(20) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `dh874`
--


/*!40000 ALTER TABLE `dh874` DISABLE KEYS */;
LOCK TABLES `dh874` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `dh874` ENABLE KEYS */;

--
-- Table structure for table `dh988`
--

CREATE TABLE `dh988` (
  `id` bigint(20) NOT NULL,
  `uf994` decimal(12,0) default NULL,
  `uf996` datetime default NULL,
  `uf998` bigint(20) default NULL,
  `uf1000` char(200) default NULL,
  `uf1219` decimal(12,2) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `dh988`
--


/*!40000 ALTER TABLE `dh988` DISABLE KEYS */;
LOCK TABLES `dh988` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `dh988` ENABLE KEYS */;

--
-- Table structure for table `dt101_126`
--

CREATE TABLE `dt101_126` (
  `id` bigint(20) NOT NULL,
  `idd` bigint(20) default NULL,
  `ln` bigint(20) default NULL,
  `uf127` bigint(20) default NULL,
  `uf140` decimal(10,0) default NULL,
  `uf142` decimal(12,2) default NULL,
  `uf356` char(254) default NULL,
  `uf448` decimal(12,2) default NULL,
  PRIMARY KEY  (`id`),
  KEY `dt101_126_idx0` (`idd`),
  KEY `dt101_126_idx1` (`ln`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `dt101_126`
--


/*!40000 ALTER TABLE `dt101_126` DISABLE KEYS */;
LOCK TABLES `dt101_126` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `dt101_126` ENABLE KEYS */;

--
-- Table structure for table `dt576_588`
--

CREATE TABLE `dt576_588` (
  `id` bigint(20) NOT NULL,
  `idd` bigint(20) default NULL,
  `ln` bigint(20) default NULL,
  `uf589` bigint(20) default NULL,
  `uf591` decimal(12,0) default NULL,
  `uf593` decimal(14,2) default NULL,
  `uf768` decimal(14,2) default NULL,
  `uf770` decimal(14,2) default NULL,
  `uf772` decimal(14,2) default NULL,
  `uf774` decimal(14,2) default NULL,
  PRIMARY KEY  (`id`),
  KEY `dt576_588_idx0` (`idd`),
  KEY `dt576_588_idx1` (`ln`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `dt576_588`
--


/*!40000 ALTER TABLE `dt576_588` DISABLE KEYS */;
LOCK TABLES `dt576_588` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `dt576_588` ENABLE KEYS */;

--
-- Table structure for table `dt874_886`
--

CREATE TABLE `dt874_886` (
  `id` bigint(20) NOT NULL,
  `idd` bigint(20) default NULL,
  `ln` bigint(20) default NULL,
  `uf887` bigint(20) default NULL,
  `uf889` char(50) default NULL,
  `uf890` decimal(10,0) default NULL,
  `uf892` decimal(14,2) default NULL,
  `uf895` decimal(14,2) default NULL,
  PRIMARY KEY  (`id`),
  KEY `dt874_886_idx0` (`idd`),
  KEY `dt874_886_idx1` (`ln`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `dt874_886`
--


/*!40000 ALTER TABLE `dt874_886` DISABLE KEYS */;
LOCK TABLES `dt874_886` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `dt874_886` ENABLE KEYS */;

--
-- Table structure for table `idc`
--

CREATE TABLE `idc` (
  `tname` char(40) default NULL,
  `uindices` char(240) default NULL,
  `idxname` char(64) default NULL,
  KEY `idc_idx0` (`tname`),
  KEY `idc_idx1` (`uindices`),
  KEY `idc_idx2` (`idxname`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `idc`
--


/*!40000 ALTER TABLE `idc` DISABLE KEYS */;
LOCK TABLES `idc` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `idc` ENABLE KEYS */;

--
-- Table structure for table `r_rl`
--

CREATE TABLE `r_rl` (
  `idr` bigint(20) default NULL,
  `permission` int(11) default NULL,
  `object` bigint(20) default NULL,
  KEY `r_rl_idx0` (`idr`),
  KEY `r_rl_idx1` (`permission`),
  KEY `r_rl_idx2` (`object`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `r_rl`
--


/*!40000 ALTER TABLE `r_rl` DISABLE KEYS */;
LOCK TABLES `r_rl` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `r_rl` ENABLE KEYS */;

--
-- Table structure for table `ra296`
--

CREATE TABLE `ra296` (
  `id` bigint(20) NOT NULL,
  `idd` bigint(20) default NULL,
  `iddt` bigint(20) default NULL,
  `ln` bigint(20) default NULL,
  `date` datetime default NULL,
  `uf814` decimal(10,0) default NULL,
  `uf1324` decimal(14,2) default NULL,
  `uf302` char(10) default NULL,
  `uf304` char(10) default NULL,
  `uf308` bigint(20) default NULL,
  `uf321` bigint(20) default NULL,
  `uf1144` bigint(20) default NULL,
  `uf298` char(200) default NULL,
  PRIMARY KEY  (`id`),
  KEY `ra296_idx0` (`idd`),
  KEY `ra296_idx1` (`iddt`),
  KEY `ra296_idx2` (`ln`),
  KEY `ra296_idx3` (`date`),
  KEY `ra296_idx4` (`uf814`),
  KEY `ra296_idx5` (`uf1324`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ra296`
--


/*!40000 ALTER TABLE `ra296` DISABLE KEYS */;
LOCK TABLES `ra296` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `ra296` ENABLE KEYS */;

--
-- Table structure for table `ra296_d1144`
--

CREATE TABLE `ra296_d1144` (
  `date` datetime default NULL,
  `uf1144` bigint(20) default NULL,
  `uf814` decimal(10,0) default NULL,
  `uf1324` decimal(14,2) default NULL,
  KEY `ra296_d1144_idx0` (`date`),
  KEY `ra296_d1144_idx1` (`uf814`),
  KEY `ra296_d1144_idx2` (`uf1324`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ra296_d1144`
--


/*!40000 ALTER TABLE `ra296_d1144` DISABLE KEYS */;
LOCK TABLES `ra296_d1144` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `ra296_d1144` ENABLE KEYS */;

--
-- Table structure for table `ra296_d302`
--

CREATE TABLE `ra296_d302` (
  `date` datetime default NULL,
  `uf302` char(10) default NULL,
  `uf814` decimal(10,0) default NULL,
  `uf1324` decimal(14,2) default NULL,
  KEY `ra296_d302_idx0` (`date`),
  KEY `ra296_d302_idx1` (`uf814`),
  KEY `ra296_d302_idx2` (`uf1324`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ra296_d302`
--


/*!40000 ALTER TABLE `ra296_d302` DISABLE KEYS */;
LOCK TABLES `ra296_d302` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `ra296_d302` ENABLE KEYS */;

--
-- Table structure for table `ra296_d304`
--

CREATE TABLE `ra296_d304` (
  `date` datetime default NULL,
  `uf304` char(10) default NULL,
  `uf814` decimal(10,0) default NULL,
  `uf1324` decimal(14,2) default NULL,
  KEY `ra296_d304_idx0` (`date`),
  KEY `ra296_d304_idx1` (`uf814`),
  KEY `ra296_d304_idx2` (`uf1324`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ra296_d304`
--


/*!40000 ALTER TABLE `ra296_d304` DISABLE KEYS */;
LOCK TABLES `ra296_d304` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `ra296_d304` ENABLE KEYS */;

--
-- Table structure for table `ra296_d308`
--

CREATE TABLE `ra296_d308` (
  `date` datetime default NULL,
  `uf308` bigint(20) default NULL,
  `uf814` decimal(10,0) default NULL,
  `uf1324` decimal(14,2) default NULL,
  KEY `ra296_d308_idx0` (`date`),
  KEY `ra296_d308_idx1` (`uf814`),
  KEY `ra296_d308_idx2` (`uf1324`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ra296_d308`
--


/*!40000 ALTER TABLE `ra296_d308` DISABLE KEYS */;
LOCK TABLES `ra296_d308` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `ra296_d308` ENABLE KEYS */;

--
-- Table structure for table `ra296_d321`
--

CREATE TABLE `ra296_d321` (
  `date` datetime default NULL,
  `uf321` bigint(20) default NULL,
  `uf814` decimal(10,0) default NULL,
  `uf1324` decimal(14,2) default NULL,
  KEY `ra296_d321_idx0` (`date`),
  KEY `ra296_d321_idx1` (`uf814`),
  KEY `ra296_d321_idx2` (`uf1324`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ra296_d321`
--


/*!40000 ALTER TABLE `ra296_d321` DISABLE KEYS */;
LOCK TABLES `ra296_d321` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `ra296_d321` ENABLE KEYS */;

--
-- Table structure for table `rl`
--

CREATE TABLE `rl` (
  `id` bigint(20) NOT NULL,
  `name` char(50) default NULL,
  PRIMARY KEY  (`id`),
  KEY `rl_idx0` (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `rl`
--


/*!40000 ALTER TABLE `rl` DISABLE KEYS */;
LOCK TABLES `rl` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `rl` ENABLE KEYS */;

--
-- Table structure for table `uniques`
--

CREATE TABLE `uniques` (
  `id` bigint(20) NOT NULL auto_increment,
  `otype` int(11) default NULL,
  `df` char(1) default NULL,
  PRIMARY KEY  (`id`),
  KEY `uniques_idx0` (`otype`),
  KEY `uniques_idx1` (`df`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `uniques`
--


/*!40000 ALTER TABLE `uniques` DISABLE KEYS */;
LOCK TABLES `uniques` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `uniques` ENABLE KEYS */;

--
-- Table structure for table `usr`
--

CREATE TABLE `usr` (
  `id` bigint(20) NOT NULL,
  `fname` char(25) default NULL,
  `lname` char(30) default NULL,
  `login` char(20) default NULL,
  `password` char(100) default NULL,
  PRIMARY KEY  (`id`),
  KEY `usr_idx0` (`fname`),
  KEY `usr_idx1` (`lname`),
  KEY `usr_idx2` (`login`),
  KEY `usr_idx3` (`password`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `usr`
--


/*!40000 ALTER TABLE `usr` DISABLE KEYS */;
LOCK TABLES `usr` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `usr` ENABLE KEYS */;

--
-- Table structure for table `usr_rl`
--

CREATE TABLE `usr_rl` (
  `id` bigint(20) default NULL,
  `idr` bigint(20) default NULL,
  KEY `usr_rl_idx0` (`id`),
  KEY `usr_rl_idx1` (`idr`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `usr_rl`
--


/*!40000 ALTER TABLE `usr_rl` DISABLE KEYS */;
LOCK TABLES `usr_rl` WRITE;
UNLOCK TABLES;
/*!40000 ALTER TABLE `usr_rl` ENABLE KEYS */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

