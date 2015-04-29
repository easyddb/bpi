api = 2
core = 7.x

; Projects
projects[date][subdir] = "contrib"
projects[date][version] = "2.8"

projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.0-alpha3"

; This version of media is tested to work with both images and videos.
projects[media][type] = "module"
projects[media][subdir] = "contrib"
projects[media][download][type] = "git"
projects[media][download][url] = "http://git.drupal.org/project/media.git"
projects[media][download][revision] = "c3cda2b"

projects[ding_popup][type] = "module"
projects[ding_popup][download][type] = "git"
projects[ding_popup][download][url] = "git@github.com:ding2/ding_popup.git"
projects[ding_popup][download][tag] = "7.x-2.0.0"

libraries[bpi-client][destination] = "modules/bpi/lib"
libraries[bpi-client][download][type] = "git"
libraries[bpi-client][download][url] = "git@github.com:ding2/bpi-client.git"
libraries[bpi-client][download][tag] = "7.x-2.0.0"

projects[ding_content][type] = "module"
projects[ding_content][download][type] = "git"
projects[ding_content][download][url] = "git@github.com:easyddb/ding_content.git"
projects[ding_content][download][tag] = ""
projects[ding_content][download][branch] = "easyddb"
