extends App

func _run_app() -> Widget:
	var style = TextStyle.new();
	print(style.color);
	Test.new(1) == Test.new(1);
	return null;

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass

class Test extends RefCounted:
	var i:int = 0;
	
	func _init(i) -> void:
		self.i = i;
