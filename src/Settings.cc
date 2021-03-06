/*
 * Copyright (C) 2011 Christoph Mende

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <string>
#include <iostream>

#include <giomm.h>

#include "Settings.h"

Settings::Settings()
{
	// TODO support alternative filenames
	group = "foobot";
	config.load_from_file("foobot.conf");
}

gint Settings::get_int(const gchar* prop)
{
	gint result = 0;
	try {
		result = config.get_integer(group, prop);
	} catch (Glib::KeyFileError &err) {
		std::cerr << "Failed to read: " << err.what() << std::endl;
	}
	return result;
}

std::string Settings::get_string(const gchar* prop)
{
	std::string result;
	try {
		result = config.get_string(group, prop);
	} catch (Glib::KeyFileError &err) {
		std::cerr << "Failed to read: " << err.what() << std::endl;
	}
	return result;
}
