#!/usr/bin/perl
#
# Copyright (c) 2013 by FEI Company. All rights reserved
#
# On Windows platforms it requires Strawbery Perl installed.
#
# Created: Milan Matlak (milan.matlak@fei.com)
#
#############################################################################

use strict;
use warnings;
use File::Copy;

#
# constants
use constant VERSION => 0.1; 
use constant TEMPLATE_TEST_AUTO_NAME => "TemplateTestAuto";
use constant TEMPLATE_TEST_MANUAL_NAME => "TemplateTestManual";
use constant TEMPLATE_TEST_MONITOR_NAME => "TemplateTestMonitor";
use constant TEMPLATE_COPYEAR => "TEMPLATE_COPYRIGHT";

#
# Globals
#my @filesToUpdate = glob("src/*.cpp src/*.h src/*.idl src/*.rc src/*.rgs src/*.sln src/*.vcxproj src/*.filters src/*.mc");


#############################################################################
# SUBROUTINES
#############################################################################

sub getBrickTestType()
{
  my $type = <STDIN> ;
  chomp $type;

  while ($type < 1 && $type > 3) {
    print "Choose 1, 2 or 3: ";
    $type = <STDIN> ;
    chomp $type;
  }

  return $type;
}

sub getBrickTestName()
{
  my $name = <STDIN> ;
  chomp $name;

  while ($name eq "") {
    print "It should not be empty. Try once again: ";
    $name = <STDIN> ;
    chomp $name;
  }
  
  return ucfirst $name;
}

sub updateCopyrights {
  my @date = localtime(time);
  my $year = $date[5] + 1900;

  foreach (@_)
  {
    my $cmd = "s/".TEMPLATE_COPYEAR."/${year}/g";
    my @myarray = `perl -pi.bak -e "$cmd" $_`;
    unlink $_.".bak";
  }
}


#############################################################################
# MAIN
#############################################################################

print "\nTAD Brick Test Craetor ver. ".VERSION."\n";
print "Copyright (c) 2013 by FEI Company. All rights reserved.\n\n";

#
# Parameters
my $brickTestType;
my $brickTestName;
my $selectedTestTemplate;

#
# Get test type and name
print "Enter the brick test type (1 - Auto, 2 - Manual, 3 - Monitor): ";
$brickTestType = getBrickTestType();
print "Enter the brick test name: ";
$brickTestName = getBrickTestName();

print "\n";

#
# Select file names to be copied to the src directory and updated there
$selectedTestTemplate = TEMPLATE_TEST_AUTO_NAME if ($brickTestType == 1);
$selectedTestTemplate = TEMPLATE_TEST_MANUAL_NAME if ($brickTestType == 2);
$selectedTestTemplate = TEMPLATE_TEST_MONITOR_NAME if ($brickTestType == 3);

#
# Copy selected files to src direcotry 
my @filesToCopy = glob("tests/${selectedTestTemplate}.*");
foreach (@filesToCopy) { copy ($_, "src/"); }

my @filesToUpdate = glob("src/$selectedTestTemplate.*");

#
# Update Copyrights
print "Updating copyright headers.\n";
updateCopyrights(@filesToUpdate);

#
# Update all names inside
foreach (@filesToUpdate)
{
  my $cmd = "s/$selectedTestTemplate/${brickTestName}/g";
  my @myarray = `perl -pi.bak -e "$cmd" $_`;
  unlink $_.".bak";

  print "Updating file: $_\n"."@myarray";
}

#
# Rename the selected tests
foreach (@filesToUpdate)
{
  my $srcname = $_;
  my $dstname = $srcname;
  $dstname =~ s/$selectedTestTemplate/$brickTestName/;

  print "Renaming $srcname to $dstname\n";
  move ($srcname, $dstname);
}


#
# We're finally done
print "\n\nTad brick test ${brickTestName} created.\n";
print "Now you can add it to your VS project.\n";
print "Do not forget to update .reg file manually\n\n";

# Wait for a key to exit
print "Press enter to exit...";
<STDIN>;