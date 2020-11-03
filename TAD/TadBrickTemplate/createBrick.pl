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
use Win32;

#
# constants
use constant VERSION => 0.1; 
use constant TEMPLATE_NAME => "TadBrickTemplate";
use constant TEMPLATE_GUID1 => "TEMPLATEGUID1";
use constant TEMPLATE_GUID2 => "TEMPLATEGUID2";
use constant TEMPLATE_COPYEAR => "TEMPLATE_COPYRIGHT";

#
# Globals
my @filesToUpdate = glob("src/*.cpp src/*.h src/*.idl src/*.rc src/*.rgs src/*.sln src/*.vcxproj src/*.filters src/*.mc");


#############################################################################
# MAIN
#############################################################################

print "\nTAD Brick Craetor ver. ".VERSION."\n";
print "Copyright (c) 2013 by FEI Company. All rights reserved.\n\n";

#
# Parameters
my $brickName="";
my @genGuid=();

#
# Generate GUIDs
$genGuid[0] = Win32::GuidGen();
$genGuid[1] = Win32::GuidGen();
# remove everything except A-Z 0-9 -
$genGuid[0] =~ s/[^\dA-Z-]//g;
$genGuid[1] =~ s/[^\dA-Z-]//g;

#
# Get template name
print "Enter the brick name: ";

while ($brickName eq "") {
  $brickName = <STDIN> ;
  chomp $brickName;

  if ($brickName eq "") {
    print "It should not be empty. Try once again: ";
  }
}

$brickName = ucfirst $brickName;
print "\n";

#
# Update Copyrights
print "Updating copyright headers.\n";

my @date = localtime(time);
my $year = $date[5] + 1900;

foreach (glob("src/*"))
{
  my $cmd = "s/".TEMPLATE_COPYEAR."/${year}/g";
  my @myarray = `perl -pi.bak -e "$cmd" $_`;
  unlink $_.".bak";
}

#
# Update all names inside
foreach (@filesToUpdate)
{
  my $cmd = "s/".TEMPLATE_NAME."/${brickName}/g";
  my @myarray = `perl -pi.bak -e "$cmd" $_`;
  unlink $_.".bak";

  print "Updating file: $_\n"."@myarray";
}

#
# Update GUIDS inside the .rgs and .idl file
foreach (glob("src/*.rgs src/*.idl"))
{ 
  my $cmd = "s/".TEMPLATE_GUID1."/".$genGuid[0]."/g";
  my @myarray = `perl -pi.bak -e "$cmd" $_`;
  unlink $_.".bak";

  $cmd = "s/".TEMPLATE_GUID2."/".$genGuid[1]."/g";
  @myarray = `perl -pi.bak -e "$cmd" $_`;
  unlink $_.".bak"; 

  print "Updating file: $_\n"."@myarray";  
}

#
# Rename all the filenames in the src directory
my @searchFiles = glob("src/".TEMPLATE_NAME."*");
foreach (@searchFiles)
{
  my $srcname = $_;
  my $dstname = $srcname;
  $dstname =~ s/\Q${\TEMPLATE_NAME}\E/$brickName/;

  print "Renaming $srcname to $dstname\n";
  move ($srcname, $dstname);
}

#
# Update reg file
my $cmd = "s/".TEMPLATE_NAME."/${brickName}/g";
my $origRegFile = TEMPLATE_NAME.".reg";
my $destRegFile = $brickName.".reg";

print "Updating $origRegFile\n";
my @myarray = `perl -pi.bak -e "$cmd" $origRegFile`;
unlink "${origRegFile}.bak";

print "Renaming $origRegFile to $destRegFile\n";
move ($origRegFile, $destRegFile);
                                 

#
# We're finally done
print "\n\nTad brick ${brickName} created.\n";
print "Now you can open the project in VS.\n";
print "Do not forget to create at least one brick test with using of createBrickTest\n\n";

# Wait for a key to exit
print "Press enter to exit...";
<STDIN>;