(function($) {
    Drupal.behaviors.dnpartner = {
        attach: function(context, settings) {
            if (Drupal.settings.dnpartner && Drupal.settings.dnpartner.payment == "true") {
                $("#edit-total").keyup(function(){
                    var sum = $(this).val();
                    $("#edit-certificates-row-0-sum-0").val(sum);
                });
            }
			if (Drupal.settings.dnpartner && Drupal.settings.dnpartner.operations == "true"){
				/*($("#edit-paid").find("option[value=1]").text('ДАДАДА'));
				($("#edit-paid").find("option[value=0]").text('НЕТ'));
				alert('f');*/
			}
        }
    };
    Drupal.ajax.prototype.commands.insert_brand = function(ajax, response, status) {
        $("#brand").remove();
        $(".form-item-partner").after("<div id=\"brand\">" + response.data + "</div>");
    };
}(jQuery));

