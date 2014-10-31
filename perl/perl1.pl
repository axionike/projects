#!/usr/bin/perl

# Playing around with Perl. This doesn't do what it's supposed to.
# Check out perl2.pl for a working script.


use strict;
use warnings;

open(FILE, '<' ,"perltest.txt") or die $!;

my %hash;
my $true = 1;
my $false = 0;
my ($header, $values, $value1, $value2, $value3);
my ($heading, $i);
my @fields;
my @value;

while (<FILE>){
  chomp;
  next if /^$/;
  if (/^TEST/){
    $header = $true;
    $values = $false;
    @fields = split;
    $heading = $fields[0];
    push @{$hash{$heading}{'TEST_HEADING'}} , @fields;
    $i = 0;
    next;
  }
  elsif ( /\d+/ ){
    $header = $false;
    $values = $true;
    next;
  }
  if ( $values ){
    foreach my $line (<FILE>) {
    @value = split (/\s+/, $line);
    $value1 = $value[0];
    $value2 = $value[1];
    $value3 = $value[2];
  }
    my $values_row = join '', 'value ', $i;
    push @{$hash{$heading}{$values_row}}, @value;
    $i++;
  }
  else {
    print "Successful elsif\n";
  }
}
open my $out, '>', 'parse.txt';
for my $v ( keys %hash ){
  print $out "heading: $v\n";
  for my $rec ( keys %{$hash{$v}} ){
    print $out "\tvalue:\t$rec\n";
    print $out "\t\t";
    for my $fld ( @{$hash{$v}{$rec}} ){
      print $out "$fld\t";
    }
    print $out "\n";
  }
}
close $out;
