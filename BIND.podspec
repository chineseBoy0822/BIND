
Pod::Spec.new do |s|

  s.name         = "BIND"
  s.version      = "1.2.0"
  s.summary      = "Data Binding and MVVM for iOS."

  s.description  = <<-DESC
Data Binding and MVVM for iOS. 
- **data binding** from **XIBs** or **code** by using a custom **BIND DSL**
- **data transforms** by using subclasses of `NSValueTransformer`
- **protocols** and **abstract classes** to make your **MVVM**-ing easier
- **lightweight** (200ish lines of code)
                   DESC

  s.homepage     = "https://github.com/markohlebar/BIND"
  s.license      = { :type => "MIT", :file => "LICENSE.md" }
  s.author             = { "Marko Hlebar" => "marko.hlebar@gmail.com" }
  s.social_media_url   = "https://twitter.com/markohlebar"

  s.source       = { :git => "https://github.com/markohlebar/BIND.git", :tag => "1.2.0" }
  s.source_files  = "BIND", "BIND/**/*.{h,m}"
  s.ios.exclude_files = "BIND/Categories/OSX/**/*.{h,m}"
  s.osx.exclude_files = "BIND/Categories/iOS/**/*.{h,m}"
  
  # s.public_header_files = "Classes/**/*.h"
  s.prefix_header_file = 'BIND-PrefixHeader.pch'
  s.requires_arc = true
  s.platform = :osx, "10.8"
  s.platform = :ios, "7.0"

  s.dependency 'libextobjc'

end
