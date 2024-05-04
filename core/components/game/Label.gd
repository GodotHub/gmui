extends Text


# Called when the node enters the scene tree for the first time.
func _ready():
	print(ThemeDB.get_default_theme().get_stylebox('normal', 'Label'))
	print(ThemeDB.get_default_theme().get_font('font', 'Label'));
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
