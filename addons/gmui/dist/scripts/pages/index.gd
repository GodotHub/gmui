extends "res://addons/gmui/dist/super_scripts/pages/index.gd"


var data = await reactive({'firstName': '张', 'lastName': '四'})

func fullName():
	return data.rget('firstName') + data.rget('lastName')

func _ready():
	computed(fullName)

func _mounted():
	gmui.refs['btn'].rnode.pressed.connect(
		func():
			data.rset('firstName', '李')
	)
