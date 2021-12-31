# Zeus

**If you find use in this, it would be great if you would credit me, or if you want to support me even more, [Donate](https://www.paypal.me/scobalula). These tools take a ton of time to make and I could easily keep them to myself or charge for them.**

This is a tool that will allow you to convert bsp files produced by Black Ops III's cod2map64 to obj or xmodel_export. These can then be opened in Maya, etc. for creating xcams, etc. or put straight back into APE to reuse in any way you want.

# Using Zeus

**This tool is primarily provided for Black Ops 3 mappers looking to create cinematics, converting large parts of their maps to models, etc. If you're looking for the tool to do something more, then it's not for you.**

To download Zeus, [Click Here](https://github.com/Scobalula/Zeus/releases).

Using Zeus is quite simple, simply compile your map and then navigate to `BlackOps3\share\raw\maps` and go into the mp or zm folder and find the d3dbsp file for your map, then drag it onto the tool.

If you would like to convert a particular part of your map, or a prefab, you can pack them into a prefab, then pull just that map file onto Zeus to invoke Black Ops 3's compiler, a d3dbsp file in the maps folder will be produced that Zeus will accept. Please note your map file needs at least 1 brush (can be caulk) for the compiler to process it.

Finally, once you bring your model into APE, it is recommended to tick "Preserve original UVs", this allows the UVs to be stored with higher precision that is required due to the large UV coordinates used by map geo.

In the future some further options for filtering geo, etc. will be provided.

# License/Disclaimer

Zeus was mostly made to suit my needs and it does what I want to do, however, I am open to suggestions or feature requests within reason.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.