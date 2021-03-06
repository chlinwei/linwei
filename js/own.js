// 添加事件
function addLoadEvent(func){
	var oldonload = window.onload;
	if(typeof window.onload !== 'function'){
		window.onload = func;	
	}else{
		window.onload = function(){
			oldonload();
			func();
		}
	}
}



//insertAfter函数
function insertAfter(newElement,targetElement){
	var parent = targetElement.parentNode;
	if(parent.lastChild === targetElement){
		parent.appendChild(newElement);
	}else{
		parent.insertBefore(newElement,targetElement.nextElementSibling);
	}
}

//获取css样式
function getStyle(obj,attr){
	if(obj.currentStyle[attr]){
		return obj.currentStyle[attr];
	}else{
		return obj.getComputedStyle(obj,false )[attr];
	}

}
