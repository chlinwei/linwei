function sum(n1,n2){
	return n1 + n2;
}
function callSum(n1,n2){
	return sum.apply(this,arguments);
}


console.log(callSum(10,20));
