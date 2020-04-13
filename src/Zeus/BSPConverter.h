#pragma once

class BSPConverter
{
public:
    // Bo3 BSP Magic (IBSP)
    const uint32_t Magic = 0x50534249;
    // Bo3 BSP Version
    const uint32_t Version = 0x5F;
    // BSP Entity Holder
    class D3DBSPEntity
    {
        
    };
    // Bo3 BSP Lump Types
    enum D3DBSPLumpType : uint32_t
    {
        LUMP_MATERIALS,
        LUMP_LIGHTBYTES,
        LUMP_LIGHTGRIDENTRIES,
        LUMP_LIGHTGRIDCOLORS,
        LUMP_PLANES,
        LUMP_BRUSHSIDES,
        LUMP_BRUSHSIDEEDGECOUNTS,
        LUMP_BRUSHEDGES,
        LUMP_BRUSHES,
        LUMP_TRIANGLES,
        LUMP_DRAWVERTS,
        LUMP_DRAWINDICES,
        LUMP_CULLGROUPS,
        LUMP_CULLGROUPINDICES,
        LUMP_LIGHTBYTES_UNCOMPRESSED,
        LUMP_PORTALVERTS,
        LUMP_UINDS,
        LUMP_BRUSHVERTSCOUNTS,
        LUMP_BRUSHVERTS,
        LUMP_AABBTREES,
        LUMP_CELLS,
        LUMP_PORTALS,
        LUMP_NODES,
        LUMP_LEAFS,
        LUMP_LEAFBRUSHES,
        LUMP_LEAFSURFACES,
        LUMP_COLLISIONVERTS,
        LUMP_COLLISIONTRIS,
        LUMP_COLLISIONEDGEWALKABLE,
        LUMP_COLLISIONBORDERS,
        LUMP_COLLISIONPARTITIONS,
        LUMP_COLLISIONAABBS,
        LUMP_MODELS,
        LUMP_VISIBILITY,
        LUMP_ENTITIES,
        LUMP_PATHCONNECTIONS,
        LUMP_VERTEX_LAYER_DATA,
        LUMP_LIGHTGRIDHEADER,
        LUMP_LIGHTGRIDROWS,
        LUMP_SIMPLELIGHTMAPBYTES,
        LUMP_LIGHTGRID2D_LIGHTS,
        LUMP_LIGHTGRID2D_INDICES,
        LUMP_LIGHTGRID2D_POINTS,
        LUMP_LIGHTGRID2D_CELLS,
        LUMP_LIGHT_CORONAS,
        LUMP_SHADOWMAP_VOLUMES,
        LUMP_SHADOWMAP_VOLUME_PLANES,
        LUMP_WORLDFOG_VOLUMES,
        LUMP_WORLDFOG_VOLUME_PLANES,
        LUMP_VISION_VOLUMES,
        LUMP_VISION_VOLUME_PLANES,
        LUMP_OCCLUDERS,
        LUMP_OUTDOORBOUNDS,
        LUMP_STATIC_MODEL_DATA,
        LUMP_SKY_GRID_VOLUMES,
        LUMP_LIGHTING_INFO,
        LUMP_SMODEL_LIGHTMAP_VCOLORS,
        LUMP_SMODEL_LIGHTMAP_VC_INSTS,
        LUMP_SIEGE_SKIN_MODEL_INSTS,
        LUMP_LIGHTGRIDCOEFFS,
        LUMP_LUT_VOLUMES,
        LUMP_LUT_VOLUME_PLANES,
        LUMP_WORLDFOG_MODIFIER_VOLUMES,
        LUMP_WORLDFOG_MODIFIER_VOLUME_PLANES,
        LUMP_UMBRA_SCENE,
        LUMP_SIEGE_ANIMS,
        LUMP_SIEGE_ANIMS_AUTOPLAY,
        LUMP_TRIGGER_SLABS,
        LUMP_TRIGGER_HULLS,
        LUMP_TRIGGER_MODELS,
        LUMP_DECAL_SORTING,
        LUMP_LITFOG_VOLUMES,
        LUMP_VOLUME_DECALS,
        LUMP_VOLUME_DECALS_REVEAL,
        LUMP_POSED_STATIC_MODEL_INSTANCE,
        LUMP_UMBRA_SCENE1,
        LUMP_UMBRA_PARAMS,
        LUMP_BRUSH_XMESHES
    };
#if _DEBUG
    // Bo3 BSP Lump Type Names
    const char* D3DBSPLumpTypeNames[78] =
    {
        "LUMP_MATERIALS",
        "LUMP_LIGHTBYTES",
        "LUMP_LIGHTGRIDENTRIES",
        "LUMP_LIGHTGRIDCOLORS",
        "LUMP_PLANES",
        "LUMP_BRUSHSIDES",
        "LUMP_BRUSHSIDEEDGECOUNTS",
        "LUMP_BRUSHEDGES",
        "LUMP_BRUSHES",
        "LUMP_TRIANGLES",
        "LUMP_DRAWVERTS",
        "LUMP_DRAWINDICES",
        "LUMP_CULLGROUPS",
        "LUMP_CULLGROUPINDICES",
        "LUMP_LIGHTBYTES_UNCOMPRESSED",
        "LUMP_PORTALVERTS",
        "LUMP_UINDS",
        "LUMP_BRUSHVERTSCOUNTS",
        "LUMP_BRUSHVERTS",
        "LUMP_AABBTREES",
        "LUMP_CELLS",
        "LUMP_PORTALS",
        "LUMP_NODES",
        "LUMP_LEAFS",
        "LUMP_LEAFBRUSHES",
        "LUMP_LEAFSURFACES",
        "LUMP_COLLISIONVERTS",
        "LUMP_COLLISIONTRIS",
        "LUMP_COLLISIONEDGEWALKABLE",
        "LUMP_COLLISIONBORDERS",
        "LUMP_COLLISIONPARTITIONS",
        "LUMP_COLLISIONAABBS",
        "LUMP_MODELS",
        "LUMP_VISIBILITY",
        "LUMP_ENTITIES",
        "LUMP_PATHCONNECTIONS",
        "LUMP_VERTEX_LAYER_DATA",
        "LUMP_LIGHTGRIDHEADER",
        "LUMP_LIGHTGRIDROWS",
        "LUMP_SIMPLELIGHTMAPBYTES",
        "LUMP_LIGHTGRID2D_LIGHTS",
        "LUMP_LIGHTGRID2D_INDICES",
        "LUMP_LIGHTGRID2D_POINTS",
        "LUMP_LIGHTGRID2D_CELLS",
        "LUMP_LIGHT_CORONAS",
        "LUMP_SHADOWMAP_VOLUMES",
        "LUMP_SHADOWMAP_VOLUME_PLANES",
        "LUMP_WORLDFOG_VOLUMES",
        "LUMP_WORLDFOG_VOLUME_PLANES",
        "LUMP_VISION_VOLUMES",
        "LUMP_VISION_VOLUME_PLANES",
        "LUMP_OCCLUDERS",
        "LUMP_OUTDOORBOUNDS",
        "LUMP_STATIC_MODEL_DATA",
        "LUMP_SKY_GRID_VOLUMES",
        "LUMP_LIGHTING_INFO",
        "LUMP_SMODEL_LIGHTMAP_VCOLORS",
        "LUMP_SMODEL_LIGHTMAP_VC_INSTS",
        "LUMP_SIEGE_SKIN_MODEL_INSTS",
        "LUMP_LIGHTGRIDCOEFFS",
        "LUMP_LUT_VOLUMES",
        "LUMP_LUT_VOLUME_PLANES",
        "LUMP_WORLDFOG_MODIFIER_VOLUMES",
        "LUMP_WORLDFOG_MODIFIER_VOLUME_PLANES",
        "LUMP_UMBRA_SCENE",
        "LUMP_SIEGE_ANIMS",
        "LUMP_SIEGE_ANIMS_AUTOPLAY",
        "LUMP_TRIGGER_SLABS",
        "LUMP_TRIGGER_HULLS",
        "LUMP_TRIGGER_MODELS",
        "LUMP_DECAL_SORTING",
        "LUMP_LITFOG_VOLUMES",
        "LUMP_VOLUME_DECALS",
        "LUMP_VOLUME_DECALS_REVEAL",
        "LUMP_POSED_STATIC_MODEL_INSTANCE",
        "LUMP_UMBRA_SCENE1",
        "LUMP_UMBRA_PARAMS",
        "LUMP_BRUSH_XMESHES"
    };
#endif
    // Bo3 BSP Header
    struct D3DBSPHeader
    {
        uint32_t Magic;
        uint32_t Version;
        uint32_t LumpCount;
    };
    // Bo3 BSP Lump
    struct D3DBSPLump
    {
        D3DBSPLumpType Type;
        uint32_t Size;
    };
    // Bo3 BSP Material
    struct D3DBSPMaterial
    {
        char Name[64];
        uint64_t Flags;

        std::string ToString()
        {
            return std::string(Name);
        }
    };
    // Bo3 BSP Draw Vertex
    struct D3DBSPDrawVert
    {
        PLX::Vector3 Position;
        PLX::Vector3 Normal;
        uint8_t Color[4];
        PLX::Vector2 UV;
        uint8_t Padding[32];
    };
    // Bo3 BSP Draw Index
    struct D3DBSPDrawIndex
    {
        uint16_t Indices[3];
    };
    // Bo3 BSP Triangle
    struct D3DBSPTriangle
    {
        uint16_t MaterialIndex;
        uint8_t Padding[14];
        uint32_t VertexIndex;
        uint16_t VertexCount;
        uint16_t FaceIndexCount;
        uint32_t FaceIndexIndex;
    };
    // BSP Settings Holder
    class Settings
    {
    public:
        // BSP Files to convert
        std::vector<std::string> BSPFiles;
        // Map Files to conver
        std::vector<std::string> MapFiles;
        // General settings via command args
        std::map<std::string, std::string> Values;

        // Gets the setting by key if exists, otherwise returns default value
        std::string GetSettingValue(const std::string& key, const std::string& defaultVal)
        {
            auto setting = Values.find(key);

            if (setting != Values.end())
                return setting->second;

            return defaultVal;
        }
    };
    // Init BSP Converter
    BSPConverter() {}
    // Init BSP Converter and loads from the given path
    BSPConverter(const std::string& Path, Settings& settings)
    {
        Load(Path, settings);
    }
    // Loads from BSP File
    void Load(const std::string& Path, Settings& settings);
    // Saves to standard 3D File
    void Save(const std::string& folder, const std::string& name, Settings& settings);
    // Converts to OBJ
    void ToOBJ(const std::string& path, Settings& settings);
    // Converts to XModel Export
    void ToXME(const std::string& path, Settings& settings);
    // Disposes of the BSP Converter
    ~BSPConverter() {}
private:
    // BSP reader
    PLX::BinaryReader Reader;
    // BSP Header
    D3DBSPHeader Header;
    // List of Lumps
    std::vector<D3DBSPLump> Lumps;
    // List of materials
    std::vector<D3DBSPMaterial> Materials;
    // List of Surfaces
    std::vector<D3DBSPTriangle> Surfaces;
    // List of Vertices
    std::vector<D3DBSPDrawVert> Vertices;
    // List of Indices
    std::vector<D3DBSPDrawIndex> Indices;
    // List of Entities
    std::vector<D3DBSPEntity> Entities;

    // Loads Lump List
    void LoadLumps();
    // Loads Materials
    void LoadMaterials(const D3DBSPLump lump);
    // Loads Materials
    void LoadSurfaces(const D3DBSPLump lump);
    // Loads Materials
    void LoadVertices(const D3DBSPLump lump);
    // Loads Materials
    void LoadIndices(const D3DBSPLump lump);
    // Loads Materials
    void LoadEntities(const D3DBSPLump lump);
};

