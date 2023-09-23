
<?php


// 15

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

echo "Enter data: ";


$x = readline();

function isNumberPowerOfTwo($x){

    return $x % 2 == 0; 
}

$result = isNumberPowerOfTwo($x);
echo $result;

?>    
