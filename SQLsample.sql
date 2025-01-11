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