-- SQL LEETCODE 50 - https://leetcode.com/problems/not-boring-movies/?envType=study-plan-v2&envId=top-sql-50
-- 620. Not Boring Movies
SELECT *
FROM Cinema C
WHERE C.id % 2 <> 0
AND C.description <> "boring"
ORDER BY C.rating DESC;

-- SQL LEETCODE 50 - https://leetcode.com/problems/managers-with-at-least-5-direct-reports/description/?envType=study-plan-v2&envId=top-sql-50
-- 570. Managers with at least 5 direct reports
SELECT M.name
FROM Employee E
INNER JOIN Employee M
ON E.managerID = M.id
GROUP BY M.id
HAVING count(*) > 4;

-- SQL LEETCODE 50 - https://leetcode.com/problems/product-sales-analysis-i/description/?envType=study-plan-v2&envId=top-sql-50
-- 1068. Product Sales Analysis I
SELECT p.product_name, s.year, s.price
FROM Sales s
LEFT JOIN Product p
ON s.product_id = p.product_id

-- SQL Leetcode 50 - https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/?envType=study-plan-v2&envId=top-sql-50
-- 1378. Replace Employee ID With The Unique Identifier
SELECT EmployeeUNI.unique_id, Employees.name
FROM EmployeeUNI
RIGHT JOIN Employees 
ON Employees.id = EmployeeUNI.id;


-- SQL Leetcode 50 - https://leetcode.com/problems/big-countries/description/?envType=study-plan-v2&envId=top-sql-50  
-- 595. Big Countries
SELECT name, population, area
FROM World
WHERE 
    area >= 3000000
    OR
    population >= 25000000;

-- SQL Leetcode 50 - https://leetcode.com/problems/find-customer-referee/description/?envType=study-plan-v2&envId=top-sql-50 
-- 584. Find Customer Referee
SELECT name 
FROM Customer
WHERE referee_id != 2
OR referee_id IS NULL;

-- SQL Leetcode 50 - https://leetcode.com/problems/recyclable-and-low-fat-products/?envType=study-plan-v2&envId=top-sql-50 
-- 1757. Recyclable and Low Fat Products
SELECT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y';

-- PART 6 -
--add check constraint using SQL code
ALTER TABLE tblPerson
ADD CONSTRAINT CK_tblPerson_Age CHECK (AGE > 0 AND AGE < 150)

-- DROP CONSTRAINT
ALTER TABLE tblPerson 
DROP CONSTRAINT CK_tblPerson_Age

--PART 5 -https://www.youtube.com/watch?v=ETepOVi7Xk8
-- practicing cascading deletes - cascade, set null, set default practiced while deleting row with foreign key constraints
DELETE from tblGender WHERE ID = 3


-- PART 4 -https://www.youtube.com/watch?v=dwSqHhMl32Y
-- Want Geneder to be unknown by default if not provided. - USE DEFAULT CONSTRAINT
ALTER TABLE tblPerson 
ADD CONSTRAINT DFLT_tblPerson_GenderID
DEFAULT 3 FOR GenderID

-- Add a new column to an existing table - Alter
ALTER TABLE tblPerson
ADD Age int 
CONSTRAINT DFLT_tblPerson_Age_13
DEFAULT 13

-- Drop column from table
ALTER TABLE tblPerson
DROP CONSTRAINT DFLT_tblPerson_Age_13
GO
ALTER TABLE tblPerson
DROP COLUMN Age

-- Drop constraint (Needs Alter command)
ALTER TABLE tblPerson
DROP CONSTRAINT DFLT_tblPerson_GenderID


PART 2- https://www.youtube.com/watch?v=TuxuHHacIWU
ALTER DATABASE Sample2 MODIFY NAME = Sample3

-- stored procedure to change name of database
sp_renameDB 'Sample3', 'Sample4'


-- below line is for deletion of database. 1st line ensures only one person has access to database at time ot deletion
ALTER DATABASE Sample4 SET SINGLE_USER WITH ROLLBACK IMMEDIATE
DROP DATABASE Sample4