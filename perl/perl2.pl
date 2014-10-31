#!/usr/bin/perl

# The purpose of this script is to parse a heading and numeric values
# from a file that is formatted as such:
#
# Some Heading             Value 1         Value 2        Value 3
# ---------------------------------------------------------------
#                          12345           6778           1234
#
# The script will parse out the "Some Heading" value and comma
# separate the values into a created CSV file.
# It was originally created to parse a SQL table and index storage size query.
#
# Warning: The script doesn't cleanly parse the table yet.
# Probably needs a couple hours of tweaking the regex to fix.
#
# Feel free to use at your own risk.

use strict;
use warnings;

open(FILE, '<' ,"perltest.txt") or die $!;

my %hash;
my ($values, $value1, $value2, $value3);
my ($heading, $i);
my @fields;
my @value;

while (<FILE>){
  chomp;
  next if /^$/;
  if (/^TEST/){
    @fields = split;
    $heading = $fields[0];
    push @{$hash{$heading}{'heading'}}, @fields;
    $i = 0;
    next;
  }
  elsif ( /\s+\d+/ ){
    @value = split ' ';

    my $values_item = $i;
    push @{$hash{$heading}{$values_item}}, @value;
    $i++;
  }
  else {
    # print "Successful elsif\n";
  }
}

open my $out, '>', 'parse.csv';

for my $v ( keys %hash ){
  print $out "$v,";
  for my $rec ( keys %{$hash{$v}} ){
    for my $fld ( @{$hash{$v}{$rec}} ){
      print $out "$fld,";
    }
  }
  print $out "\n";
}

close $out;
