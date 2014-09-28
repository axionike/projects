#!/usr/bin/perl

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
