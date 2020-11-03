Brick Generator for Dummies like me ;-)
=======================================


Prerequisities:
---------------

To create a new brick template, you need:
1. Install Strawbery Perl
2. Perform the following steps.


How to create a new brick:
--------------------------

1. Create the new brick directory in the TEM_TAD\tad directory of your sandbox direcotry
2. Copy "src" and "tests" directory, the .reg file and all the .pl scripts in it
3. Move to your brick directory
4. Execute createBrick.pl first. Simply enter the same name of your new brick (directory).
   This script updates all files with your brick name.
5. If haven't met any error, you can open the solution in your VS.
6. Before you build, you need to create at least one brick test and update .reg file accorginly


How to create a new brick test:
-------------------------------
1. In your brick directory, execute createBrickTest.pl
   - enter the type of test which you wanna create the source code for
   - enter the name of the test
2. Add the newly generated .cpp and .h files into your brick project
3. There is much more to do to make your test working, but after these steps, you should be
   able to build your entire brick.
   In order to properly deploy and start TAD UI without any error and of course to see your
   brick and its test in the TAD UI, do not forget to update .reg file accordingly.


After all is generated:
-----------------------
1. Now it's time to remove all the .pl scripts, they must not be a part of your brick project
   as well as the "tests" directory
2. Put your .reg file to the TEM_TAD\Install\src\TEMTAD\<Your Brick>\ directory...
3. Creation of a working test is another story, sorry... ;)


Enjoy, ;)
Milan Matlak (milan.matlak@fei.com)