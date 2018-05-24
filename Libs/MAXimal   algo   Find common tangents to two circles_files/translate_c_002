$(function(){

	function build_contents() {
		var contents = '';
		var id_counter = 0;

		var stack = new Array;
		stack.push ({
			level: 0
		});

		function update_stack_level (item) {
			while (stack.length > 0 && stack[stack.length-1].level >= item.level)
				close_item (stack.pop());
			if (stack.length > 0)
				start_list (stack[stack.length-1]);
			start_item (item);
			stack.push (item);
		}

		function start_item (item) {
			contents += "<li><a href=\"#" + item.id + "\">" + item.title + "</a></li>";
		}
		function start_list (item) {
			if (item.list_started)  return;
			contents += "<ul>";
			item.list_started = true;
		}
		function close_item (item) {
			if (item.list_started)
				contents += "</ul>";
		}

		$('td.content').find('h1, h2, h3, h4').each(function(){
			if ($(this).parents('#disqus_thread').length > 0)
				return;

			var level = this.tagName[1];
			var title = $(this).html();
			var id = id_counter++;

			$(this).before ('<a name="' + id + '"></a>');
			$(this).attr ('id', 'header_' + id);
			
			update_stack_level ({
				level: level,
				title: title,
				id: id
			});
		});
		while (stack.length > 0)
			close_item (stack.pop());

		$('#contents-table > div').html (contents);
		$('#contents-table > div').slideDown();
	}

	build_contents();



	$('#contents-table a').click(function(){
		var sel = '#header_' + $(this).attr('href').substr(1);
		var elem = $(sel);
		var current_color = elem.css ('color');
		elem.css('color','rgb(0, 0, 187)');
		setTimeout (function(){
			elem.css('color',current_color);
		}, 300);
	});


	$('#contents-hide').click(function(){
		$(this).parent().parent().find('div').slideUp();
		$('#contents-hide').hide();
		$('#contents-show').show();
		return false;
	});
	$('#contents-show').click(function(){
		$(this).parent().parent().find('div').slideDown();
		$('#contents-show').hide();
		$('#contents-hide').show();
		return false;
	});

});
