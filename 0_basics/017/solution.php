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
echo "Enter first variable: ";
$inputNumb = readline();

function countNumberSum($inputNumb){

    $string = strval($inputNumb); 
    $array = str_split($string);
    $sum = 0;
    foreach($array as $a){
        $sum += intval($a);
    }
    return $sum;    
}

$sumOfStrNumber = countNumberSum($inputNumb);
echo $sumOfStrNumber;
?>    
