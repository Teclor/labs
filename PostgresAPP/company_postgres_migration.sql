-- MySQL dump 10.13  Distrib 8.0.20, for Win64 (x86_64)
--
-- Host: localhost    Database: company
-- ------------------------------------------------------
-- Server version	8.0.20

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table department
--

DROP TABLE IF EXISTS department;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE department (
  id SERIAL,
  name varchar(64) DEFAULT NULL,
  PRIMARY KEY (id)
);
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table employee
--

DROP TABLE IF EXISTS employee;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE employee (
  id SERIAL,
  name varchar(255) NOT NULL,
  surname varchar(255) NOT NULL,
  lastname varchar(255) DEFAULT NULL,
  PRIMARY KEY (id)
);
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table employee
--

/*!40000 ALTER TABLE employee DISABLE KEYS */;
INSERT INTO employee VALUES (1,'Арина','Котёл','Константиновна'),(2,'Алексей','Протокоркин','Сергеевич'),(3,'Елисей','Будько','Сократович'),(4,'Татьяна','Кузнецова','Александровна'),(5,'Екатерина','Борисова','Романовна'),(6,'Сергей','Сотников','Константинович'),(7,'Александр','Колосков','Егорович'),(8,'Наив','Байесовский','Классификаторович'),(9,'Леонид','Морозный','Дмитриевич'),(10,'Дмитрий','Красный','Парацельсиевич'),(11,'Алексей','Федоров',NULL),(13,'Пётр','Петров',NULL);
/*!40000 ALTER TABLE employee ENABLE KEYS */;

--
-- Dumping data for table department
--

/*!40000 ALTER TABLE department DISABLE KEYS */;
INSERT INTO department VALUES (1,'Отдел кадров'),(2,'Отдел проектов'),(3,'Управление компанией'),(4,'Обслуживание'),(5,'Дизайн'),(6,'Бухгалтерия'),(7,'Управление сотрудниками'),(8,'Отдел продаж'),(9,'Отдел развития'),(10,'Отдел работы с клиентами');
/*!40000 ALTER TABLE department ENABLE KEYS */;

--
-- Table structure for table empdata
--

DROP TABLE IF EXISTS empdata;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE empdata (
  id SERIAL,
  passport varchar(255) DEFAULT NULL,
  address varchar(255) DEFAULT NULL,
  phone varchar(64) DEFAULT NULL,
  email varchar(255) DEFAULT NULL,
  employee_id int NOT NULL,
  education varchar(255) DEFAULT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (employee_id) REFERENCES employee (id) ON DELETE CASCADE
);
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table empdata
--

/*!40000 ALTER TABLE empdata DISABLE KEYS */;
INSERT INTO empdata VALUES (1,'4717 837154','Улица Пушкина, дом 5','+73308376261','dukaqiuii@mail.ru',3,'Высшее, ВШЭ, экономист'),(2,'9237 738491','Улица Сотникова, 5','+712092717272','aiadbias@inbox.ru',2,'Высшее'),(3,'2743 937856','Улица Ленина, д. 5, кв 64','+78827216362','random.mail_eee@mail.ru',10,'Среднее-общее'),(4,'2842 937349','Улица Ленина, д. 7, кв 87','+79487472865','fdsisdinjiaaaa@yandex.ru',9,'Высшее, Юрист'),(5,'2641 732878','Проспект Маршала Жукова 99','+78392828371','skqippppp@gmail.com',4,'Высшее, Менеджер-управляющий, ВГТУ'),(6,'3619 371937','Улица Строителей, д. 5, кв 222','43-65-22','aookkakk@mail.ru',8,'Среднее-специальное, инженер, ВГТЗУ'),(7,'5626 184945','Улица Строителей, д. 2, кв 72','+74618828182','klaklakje@yandex.ru',1,'Среднее-специальное, менеджер'),(8,'5687 569198','Улица Коммунистов, д. 7, кв 89','+72991826572','feelbetterwhenlabisdone@yandex.ru',5,'Среднее-общее, МОУ СШ 12 г. Кирова'),(9,'3772 391838','Улица Крестьянская, д. 87, кв 54','89461535153','kanunika@onx.com',6,'Высшее, КГТУ, Специалист по продажам'),(10,'3231 636613','Улица Морская, д. 2','84436260011','oioioioiaaaa@me.com',7,'Среднее-специальное, инженер, ВТУ');
/*!40000 ALTER TABLE empdata ENABLE KEYS */;

--
-- Table structure for table position
--

DROP TABLE IF EXISTS position;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE position (
  id SERIAL,
  name varchar(255) DEFAULT NULL,
  salary int DEFAULT NULL,
  PRIMARY KEY (id)
);
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table position
--

/*!40000 ALTER TABLE position DISABLE KEYS */;
INSERT INTO position VALUES (1,'Директор',100000),(2,'Уборщик',20000),(3,'Старший менеджер',70000),(4,'Бухгалтер',50000),(5,'Менеджер',35000),(6,'Менеджер продаж',40000),(7,'Дизайнер',32000),(8,'Продавец',27000),(9,'HR-менеджер',35000),(10,'Заместитель директора',80000);
/*!40000 ALTER TABLE position ENABLE KEYS */;


--
-- Table structure for table user-department-position
--

DROP TABLE IF EXISTS user_department_position;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE user_department_position (
  id SERIAL,
  employee_id int NOT NULL,
  position_id int NOT NULL,
  department_id int NOT NULL,
  hired date NOT NULL,
  fired date DEFAULT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (department_id) REFERENCES department (id) ON DELETE CASCADE,
  FOREIGN KEY (employee_id) REFERENCES employee (id) ON DELETE CASCADE,
  FOREIGN KEY (position_id) REFERENCES position (id)  ON DELETE CASCADE
);
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table user-department-position
--


/*!40000 ALTER TABLE user-department-position DISABLE KEYS */;
INSERT INTO user_department_position VALUES (1,9,1,3,'2025-05-20',NULL),(2,10,9,1,'2020-07-22',NULL),(3,1,2,4,'2020-09-01',NULL),(4,2,8,10,'2020-05-20','2020-06-21'),(5,4,4,6,'2020-05-20',NULL),(6,3,3,5,'2020-09-07',NULL),(7,5,7,5,'2020-09-10',NULL),(8,7,7,5,'2020-08-05',NULL),(9,6,10,3,'2020-07-20',NULL),(10,8,6,8,'2020-07-25',NULL);
/*!40000 ALTER TABLE user-department-position ENABLE KEYS */;


--
-- Table structure for table users
--

DROP TABLE IF EXISTS users;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE users (
  id SERIAL,
  login varchar(32) NOT NULL,
  password varchar(64) NOT NULL,
  isadmin boolean NOT NULL DEFAULT 'f',
  PRIMARY KEY (id),
  UNIQUE (login)
);
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table users
--

/*!40000 ALTER TABLE users DISABLE KEYS */;
INSERT INTO users VALUES (1,'admin','21232f297a57a5a743894a0e4a801fc3','t'),(2,'guest','084e0343a0486ff05530df6c705c8bb4','f');
/*!40000 ALTER TABLE users ENABLE KEYS */;

/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-01-02  8:27:01

ALTER SEQUENCE department_id_seq RESTART WITH 11;
ALTER SEQUENCE employee_id_seq RESTART WITH 14;
ALTER SEQUENCE empdata_id_seq RESTART WITH 11;
ALTER SEQUENCE position_id_seq RESTART WITH 11;
ALTER SEQUENCE user_department_position_id_seq RESTART WITH 11;
ALTER SEQUENCE users_id_seq RESTART WITH 3;
