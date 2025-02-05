extends Control
class_name Main

enum Menu {
	MAIN,
	USERS,
	IMAGES,
	ACTIVITIES,
	RELATIONSHIPS,
	NETWORKING,
}

enum Error {
	OK = 0,
	FAILED = 1,
	ERR_UNAVAILABLE = 2,
	ERR_UNCONFIGURED = 3,
	ERR_UNAUTHORIZED = 4,
	ERR_PARAMETER_RANGE_ERROR = 5,
	ERR_OUT_OF_MEMORY = 6,
	ERR_FILE_NOT_FOUND = 7,
	ERR_FILE_BAD_DRIVE = 8,
	ERR_FILE_BAD_PATH = 9,
	ERR_FILE_NO_PERMISSION = 10,
	ERR_FILE_ALREADY_IN_USE = 11,
	ERR_FILE_CANT_OPEN = 12,
	ERR_FILE_CANT_WRITE = 13,
	ERR_FILE_CANT_READ = 14,
	ERR_FILE_UNRECOGNIZED = 15,
	ERR_FILE_CORRUPT = 16,
	ERR_FILE_MISSING_DEPENDENCIES = 17,
	ERR_FILE_EOF = 18,
	ERR_CANT_OPEN = 19,
	ERR_CANT_CREATE = 20,
	ERR_QUERY_FAILED = 21,
	ERR_ALREADY_IN_USE = 22,
	ERR_LOCKED = 23,
	ERR_TIMEOUT = 24,
	ERR_CANT_CONNECT = 25,
	ERR_CANT_RESOLVE = 26,
	ERR_CONNECTION_ERROR = 27,
	ERR_CANT_ACQUIRE_RESOURCE = 28,
	ERR_CANT_FORK = 29,
	ERR_INVALID_DATA = 30,
	ERR_INVALID_PARAMETER = 31,
	ERR_ALREADY_EXISTS = 32,
	ERR_DOES_NOT_EXIST = 33,
	ERR_DATABASE_CANT_READ = 34,
	ERR_DATABASE_CANT_WRITE = 35,
	ERR_COMPILATION_FAILED = 36,
	ERR_METHOD_NOT_FOUND = 37,
	ERR_LINK_FAILED = 38,
	ERR_SCRIPT_FAILED = 39,
	ERR_CYCLIC_LINK = 40,
	ERR_INVALID_DECLARATION = 41,
	ERR_DUPLICATE_SYMBOL = 42,
	ERR_PARSE_ERROR = 43,
	ERR_BUSY = 44,
	ERR_SKIP = 45,
	ERR_HELP = 46,
	ERR_BUG = 47,
	ERR_PRINTER_ON_FIRE = 48,
}

onready var back_button := $MarginContainer/VBoxContainer/Title/BackButton
onready var main_menu := $MarginContainer/VBoxContainer/Menu/MarginContainer/Main
onready var users_menu := $MarginContainer/VBoxContainer/Menu/MarginContainer/Users
onready var images_menu := $MarginContainer/VBoxContainer/Menu/MarginContainer/Images
onready var activities_menu := $MarginContainer/VBoxContainer/Menu/MarginContainer/Activities
onready var relationships_menu := $MarginContainer/VBoxContainer/Menu/MarginContainer/Relationships
onready var networking_menu := $MarginContainer/VBoxContainer/Menu/MarginContainer/Networking


func _on_main_switch_to(menu: int) -> void:
	match menu:
		Menu.MAIN:
			to_main()
		Menu.USERS:
			to_users()
		Menu.IMAGES:
			to_images()
		Menu.ACTIVITIES:
			to_activities()
		Menu.RELATIONSHIPS:
			to_relationships()
		Menu.NETWORKING:
			to_networking()


func _hide_all() -> void:
	back_button.disabled = false
	main_menu.visible = false
	users_menu.visible = false
	images_menu.visible = false
	activities_menu.visible = false
	relationships_menu.visible = false
	networking_menu.visible = false


func to_main() -> void:
	_hide_all()
	back_button.disabled = true
	main_menu.visible = true


func to_users() -> void:
	_hide_all()
	users_menu.visible = true


func to_images() -> void:
	_hide_all()
	images_menu.visible = true


func to_activities() -> void:
	_hide_all()
	activities_menu.visible = true


func to_relationships() -> void:
	_hide_all()
	relationships_menu.visible = true


func to_networking() -> void:
	_hide_all()
	networking_menu.visible = true
