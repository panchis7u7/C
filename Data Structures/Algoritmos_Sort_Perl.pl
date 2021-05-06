use strict;
use warnings;
use diagnostics;
use feature 'say';
use feature "switch";
use experimental qw( switch );
use v5.28.1;

say "Arreglo desordenado: ";
my @arreglo = (10,2,7,31,4,9,11,32,56,89,90,33);
print join (", ", @arreglo), "\n";
print("\n");
print("-------------------------------------\n");
print("1.- Bubble Sort\n");
print("2.- Insertion Sort\n");
print("3.- Selection Sort\n");
print("4.- Merge Sort\n");
print("5.- Quick Sort\n");
print("6.- Shell Sort\n");
print("7.- Cocktail Sort\n");
print("8.- Gnome Sort\n");
print("9.- Counting Sort\n");
print("10.- Bucket Sort\n");
print("11.- Radix Sort\n");   
print("12.- Heap Sort\n");                     
print("-------------------------------------\n");
my $desicion = <STDIN>;
given ($desicion) {
	when($_ == 1){
		say"Bubble Sort";
		my @Bub_sort = &bubble_sort(@arreglo);
		print join (", ", @Bub_sort), "\n";
	}
	when($_ == 2){
		say "Insertion Sort";
		my @Ins_sort = &insertion_sort(@arreglo);
		print join (", ", @Ins_sort), "\n";
		
	}
	when($_ == 3){
		say "Selection Sort";
		my @Sel_sort = &selection_sort(@arreglo);
		print join (", ", @Sel_sort), "\n";
	}
	when($_ == 4){
		say "Merge Sort";
		my @Mer_sort = &merge_sort(@arreglo);
		print join (", ", @Mer_sort), "\n";
	}
	when($_ == 5){
		say "Quick Sort";
		my @Qui_sort = &quick_sort(@arreglo);
		print join (", ", @Qui_sort), "\n";
	}
	when($_ == 6){
		say "Shell Sort";
		my @She_sort = &shell_sort(@arreglo);
		print join (", ", @She_sort), "\n";
	}
	when($_ == 7){
		say "Cocktail Sort";
		my @Co_sort = &cocktail_sort(@arreglo);
		print join (", ", @Co_sort), "\n";
	}
	when($_ == 8){
		say "Gnome Sort";
		my @Gno_sort = &gnome_sort(@arreglo);
		print join (", ", @Gno_sort), "\n";
	}
	when($_ == 9){
		say "Counting Sort";
		my @Cou_sort = &counting_sort(\@arreglo, 2, 31);
		print join (", ", @Cou_sort), "\n";
	}
	when($_ == 10){
		say "Bucket Sort";
		my @Buc_sort = &bucket_sort(@arreglo, 7);
		print join (", ", @Buc_sort), "\n";
	}
	when($_ == 11){
		say "Radix Sort";
		my @Rad_sort = &radix_sort(\@arreglo, 7);
		print join (", ", @Rad_sort), "\n";
	}
	when($_ == 12){
		say "Heap Sort";
		heap_sort(\@arreglo);
		print join (", ", @arreglo), "\n";
	}
	default {
		say "Desicion incorrecta!";
	}
}

#for my $k (@arreglo){
	#say $k;
#}

#1.- Bubble Sort Mejorado
sub bubble_sort {
for(my $i = 1; $i < @arreglo-1; $i++){
	if($arreglo[$i] > $arreglo[$i+1]) {
		my $temp = $arreglo[$i+1];
		$arreglo[$i+1] = $arreglo[$i];
		$arreglo[$i] = $temp;
		$i = -1;
		}
	}
	return @arreglo;
}

#2.-Insertion Sort
sub insertion_sort {
    my (@arreglo) = @_;
    foreach my $i (1 .. $#arreglo){
	    my $j = $i;
	    my $temp = $arreglo[$i];
    	while ($j >0 && $temp < $arreglo[$j-1]){
    		$arreglo[$j] = $arreglo[$j-1];
    		$j --;
		}
		$arreglo[$j]=$temp;

	}
	return @arreglo;
}

#3.-Selection Sort
sub selection_sort {
   my @list = @_;
   for my $i (0 .. $#list - 1) {
      my $min = $i;
      for my $j ($i .. $#list) {
         if ($list[$j] < $list[$min]) {
            $min = $j;
         }
      }
      if ($i != $min) {
         @list[$i, $min] = @list[$min, $i];
      }
   }
   return @list;
}

#4.-Merge Sort
sub merge_sort {
    my @x = @_;
    return @x if @x < 2;
    my $m = int @x / 2;
    my @a = merge_sort(@x[0 .. $m - 1]);
    my @b = merge_sort(@x[$m .. $#x]);
    for (@x) {
        $_ = 
        !@a            ? shift @b : 
        !@b            ? shift @a : 
        $a[0] <= $b[0] ? shift @a :
        shift @b;
    }
    @x;
}

#5.- Quick Sort
sub quick_sort {
    my @a = @_;
    return @a if @a < 2;
    my $p = pop @a;
    quick_sort(grep $_ < $p, @a), $p, quick_sort(grep $_ >= $p, @a);
}

#6.- Shell Sort
sub shell_sort {
    my (@a, $h, $i, $j, $k) = @_;
    for ($h = @a; $h = int $h / 2;) {
        for $i ($h .. $#a) {
            $k = $a[$i];
            for ($j = $i; $j >= $h && $k < $a[$j - $h]; $j -= $h) {
                $a[$j] = $a[$j - $h];
            }
            $a[$j] = $k;
        }
    }
    @a;
}

#7.- Cocktail Sort
sub cocktail_Sort {   
  my @A = @_;
  my $intercambiado = 1;
  while ($intercambiado == 1) {
    $intercambiado = 0;
    for (my $i=0; $i<($#A-1); $i+=1) {
 
      if ($A[$i] gt $A[$i+1]) {
         ($A[$i+1], $A[$i])=($A[$i], $A[$i+1]);
        $intercambiado = 1;
      } 
    }
    if ($intercambiado == 0) {
      print "no more swaps"; 
    }
    else {
    $intercambiado = 0;
    for (my $i=($#A-1); $i>0 ; $i-=1) {
 
      if($A[$i] gt $A[$i+1]) {
 
        ($A[$i+1], $A[$i])=($A[$i], $A[$i+1]);
        $intercambiado = 1;
			}
		}
    }

 }
return (@A);
}

#8.- Gnome Sort
sub gnome_sort
{
    my @a = @_;
    my $size = scalar(@a);
    my $i = 1;
    my $j = 2;
    while($i < $size) {
	if ( $a[$i-1] <= $a[$i] ) {
	    $i = $j;
	    $j++;
	} else {
	    @a[$i, $i-1] = @a[$i-1, $i];
	    $i--;
	    if ($i == 0) {
		$i = $j;
		$j++;
	    }
	}
    }
    return @a;
}

#9.- Counting Sort
sub counting_sort
{
    my ($a, $min, $max) = @_;
 
    my @cnt = (0) x ($max - $min + 1);
    $cnt[$_ - $min]++ foreach @$a;
 
    my $i = $min;
    @$a = map {($i++) x $_} @cnt;
}

#10.- Bucket Sort
sub bucket_sort
{  
	my(@a, $n) = @_;
    my @count; 
    my $i; 
    my $j;
    for ($i = 0; $i < $n; $i++){
        $count[$i] = 0;
 }
    for ($i = 0; $i < $n; $i++){
        $count[$a[$i]]++;
 }
    for ($i = 0, $j = 0; $i < $n; $i++){ 
        for(; $count[$i] > 0; ($count[$i])--){
            $a[$j++] = $i;
		}
	}
	return @a;
}   

#11.- Radix Sort
 sub radix_sort {
    my ($datos, $k) = @_;
    $k = !!$k; 
    
    if ($k) { $k < length and $k = length for @$datos }
    else { $k = length $datos->[0] }
    
    while ($k--) {
      my @cubetas;
      for (@$datos) {
        my $c = substr $_, $k, 1; 
        $c = "\0" if not defined $c;
        push @{ $cubetas[ord($c)] }, $_;
      }
    
      @$datos = map @$_, @cubetas;
    }
  }
  
#12.- Heap Sort
sub heap_sort {
    my ($a) = @_;
    my $n = @$a;
    for (my $i = ($n - 2) / 2; $i >= 0; $i--) {
        down_heap($a, $n, $i);
    }
    for (my $i = 0; $i < $n; $i++) {
        my $t = $a->[$n - $i - 1];
        $a->[$n - $i - 1] = $a->[0];
        $a->[0] = $t;
        down_heap($a, $n - $i - 1, 0);
    }
}
 
sub down_heap {
    my ($a, $n, $i) = @_;
    while (1) {
        my $j = max($a, $n, $i, 2 * $i + 1, 2 * $i + 2);
        last if $j == $i;
        my $t = $a->[$i];
        $a->[$i] = $a->[$j];
        $a->[$j] = $t;
        $i = $j;
    }
}
 
sub max {
    my ($a, $n, $i, $j, $k) = @_;
    my $m = $i;
    $m = $j if $j < $n && $a->[$j] > $a->[$m];
    $m = $k if $k < $n && $a->[$k] > $a->[$m];
    return $m;
}
 
