
<?php


/*
 * @file solution.php
 * @author Grigoret Piotr
 * @brief `proxy` task solution
 * @version 0.1
 * @date 2023-09-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

$x = $argv[1];
$y = $argv[2];

function countDays($x, $y){

    $sportsmensProgres =  $x/10;
    $days = 0;
    while($x <= $y){
        $days++;
        $x += $sportsmensProgres;
    }
    return $days;
} 

$result = countDays($x, $y);
echo $result;
?>    
