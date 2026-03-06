import CSkia

/**
 * The `Typeface` class specifies the typeface and intrinsic style of a font.
 * This is used in the paint, along with optionally algorithmic settings like
 * textSize, textskewX, textScaleX, FakeBoldText_Mask, to specify
 * how text appears when drawn (and measured).
 *
 * Typeface objects are immutable, and so they can be shared between threads.
 */
public final class Typeface {
  var handle: OpaquePointer
  var owns: Bool

  init(handle: OpaquePointer, owns: Bool) {
    self.handle = handle
    self.owns = owns
  }

  /// Returns a new typeface configured with the defaults
  public static func createDefault() -> Typeface {
    Typeface(handle: sk_typeface_make_default(), owns: true)
  }

  /**
   * Initializes a new instance to a typeface that most closely matches the requested family name and style, can fail
   * - Parameter familyName: The name of the font family. May be `nil`
   */
  public convenience init? (familyName: String?) {
    self.init(familyName: familyName, style: FontStyle.normal)
  }

  /**
   * Initializes a new instance to a typeface that most closely matches the requested family name and style, can fail
   * - Parameter familyName: The name of the font family. May be `nil`
   * - style: The style of the typeface, one of the defaults from `FontStyle` (`normal`, `bold`, `italic`, or your own constructed `FontStyle`)
   */
  public init? (familyName: String?, style: FontStyle) {
    var x: OpaquePointer?
    withUnsafePointer(to: style.native()) {
      x = sk_typeface_make_from_name(familyName, $0)
    }

    if let x {
      handle = x
      owns = true
    } else {
      return nil
    }
  }

  /**
   * Initializes a new instance to a typeface that most closely matches the requested family name and style, can fail
   *
   * This constructor calls the FontStyle constructor with the provided parameters to create your typeface
   *
   * - Parameter familyName: The name of the font family. May be `nil`
   * - Parameter weight: the desired weight
   * - Parameter width: the desired width
   * - Parameter slant: the desired slant
   */
  public convenience init? (familyName: String?, weight: FontStyle.Weight, width: FontStyle.Width, slant: FontStyle.Slant) {
    self.init(familyName: familyName, style: FontStyle(weight: weight, width: width, slant: slant))
  }

  /**
   * Initializes a new typeface from a file - for example to load a true type font, can fail
   * - Parameter file: the path to the file containing the font
   * - Parameter index: The font face index in the file
   */
  public init? (file: String, index: Int32 = 0) {
    if let x = sk_typeface_make_from_file(file, index) {
      handle = x
      owns = true
    } else {
      return nil
    }
  }

  /**
   * Return the family name for this typeface. It will always be returned
   * encoded as UTF8, but the language of the name is whatever the host
   * platform chooses.
   */
  public var familyName: String? {
    guard let ptr = sk_typeface_get_family_name(handle) else { return nil }
    return String(cString: UnsafePointer<UInt8>(ptr)!)
  }

  /// Gets the font style
  public var fontStyle: FontStyle {
    FontStyle(weight: fontWeight, width: fontWidth, slant: fontSlant)
  }

  /// Getes the font weight
  public var fontWeight: FontStyle.Weight {
    FontStyle.Weight(rawValue: sk_typeface_get_weight(handle))!
  }

  /// Getes the font width
  public var fontWidth: FontStyle.Width {
    FontStyle.Width(rawValue: sk_typeface_get_width(handle))!
  }

  /// Gets the font slant
  public var fontSlant: FontStyle.Slant {
    FontStyle.Slant(sk_typeface_get_slant(handle))
  }

//  /// Return the units-per-em value for this typeface, or zero if there is an error.
//  public var unitsPerEm: Int32 { sk_typeface_get_units_per_em(handle) }
//
//  /// Return the number of tables in the font.
//  public var tableCount: Int32 { sk_typeface_count_tables(handle) }

  /// Given a table tag, return the size of its contents, or 0 if not present
//  public func getTableSize(tag: UInt32) -> Int {
//    sk_typeface_(handle, tag)
//  }

  /**
    * Gets the contents of the specified table tag as an array, or nil if the table is not found
    *
    * - Parameter tag: The table tag whose contents are to be copied
    * - Returns: An array with the table contents, or nil on error
   */
//  public func getTableData(tag: UInt32) -> [UInt8]? {
//    let size = getTableSize(tag: tag)
//    if size == 0 {
//      return nil
//    }
//    var arr = Array<UInt8>.init(repeating: 0, count: size)
//
//    if getTableData(tag: tag, offset: 0, length: size, storage: &arr) == size {
//      return arr
//    }
//    return nil
//  }

  /**
   * Copy the contents of a table into data (allocated by the caller). Note
   * that the contents of the table will be in their native endian order
   * (which for most truetype tables is big endian). If the table tag is
   * not found, or there is an error copying the data, then 0 is returned.
   * If this happens, it is possible that some or all of the memory pointed
   * to by data may have been written to, even though an error has occured.
   *
   * - Parameter tag: The table tag whose contents are to be copied
   * - Parameter offset: The offset in bytes into the table's contents where the
   * copy should start from.
   * - Parameter length: The number of bytes, starting at offset, of table data
   * to copy.
   * - Parameter storage: storage address where the table contents are copied to
   * - Returns: the number of bytes actually copied into data. If offset+length
   * exceeds the table's size, then only the bytes up to the table's
   * size are actually copied, and this is the value returned. If
   * offset > the table's size, or tag is not a valid table,
   * then 0 is returned.
   */
//  public func getTableData(tag: UInt32, offset: Int, length: Int, storage: UnsafeMutablePointer<UInt8>) -> Int {
//    sk_typeface_get_table_data(handle, tag, offset, length, storage)
//  }

  ///  Return the number of glyphs in the typeface.
//  public var count: Int {
//    Int(sk_typeface_count_glyphs(handle))
//  }

  deinit {
//    if owns {
//      sk_typeface_unref(handle)
//    }
  }
}
