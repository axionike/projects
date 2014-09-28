#!/usr/bin/perl

use strict;
use warnings;

open(FILE, '<' ,"perltest.txt") or die $!;

my (%seen, $pthandle, $value1, $value2, $value3);

while(<FILE>){

chomp;
my $line = $_;

if($line =~ m/^-/){ #removing '---' lines
        # print "$line:hello\n";

}else{

if ($line = m/^TEST+/) {
$pthandle = $line;
}

elsif ($line =~ m/^\s+[1-9]/) {
($value1, $value2, $value3) = split ',', $line;
}

#$seen{$pthandle}= [$value1, $value2, $value3]; # use Hashes of array
}
}
 
print "$pthandle\n";
print "$value1";
print "$value2";
print "$value3";

close(FILE);

